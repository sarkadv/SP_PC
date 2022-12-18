#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trainfile_loader.h"
#include "word_hashtable.h"

/*
 * ------------------------------------------------------------------------------------
 * Nacte slova z testovaciho souboru a ulozi je do hash tabulky jako struktury word.
 * Vysledkem bude hash tabulka predana jako parametr hashtable_all_files.
 * ------------------------------------------------------------------------------------
 */
void load_strings_to_hashtable(word *hashtable_all_files[], char *file_name_pattern, int file_count) {
    int i;
    FILE *f_p = NULL;       /* pointer na soubor */
    char *file_name = malloc(TRAIN_FILE_NAME_LENGTH);       /* nazev trenovaciho souboru */
    char c;       /* posledni nacteny znak */
    int char_count = 0;         /* pocet nactenych znaku v poslednim retezci */
    char *string = malloc(MAX_STRING_LENGTH);   /* posledni nacteny retezec */

    for(i = 1; i <= file_count; i++) {
        /* vytvoreni nazvu trenovaciho souboru */
        sprintf(file_name, "%s%s%d%s", "train/", file_name_pattern, i, ".txt");

        f_p = fopen(file_name, "r");

        word *hashtable_one_file[HASHTABLE_SIZE];       /* hash tabulka pro jeden trenovaci soubor */
        init_hashtable(hashtable_one_file);

        if(!f_p) {      /* soubor se nepodarilo otevrit */
            printf("cant load file");
        }
        else {
            while(1) {
                c = fgetc(f_p);     /* nacteni dalsiho znaku */

                if(feof(f_p)) {     /* dosli jsme na konec souboru */
                    break;
                }

                if(c == ' ') {      /* ukonceni slova */
                    string[char_count] = '\0';

                    if(!find_by_key(hashtable_one_file, string)) {   /* slovo se v tomto souboru jeste nevyskytlo */
                        /* do hash tabulky pro tento soubor pridame aktualni slovo */
                        insert_string_to_hashtable(hashtable_one_file, string);

                        /* do hash tabulky pro vsechny soubory pridame aktualni slovo */
                        insert_string_to_hashtable(hashtable_all_files, string);
                    }

                    /* zacneme nacitat dalsi slovo - reset promennych */
                    free(string);
                    string = malloc(MAX_STRING_LENGTH);
                    char_count = 0;
                }
                else {      /* jeste jsme nedosli na konec slova */
                    string[char_count] = c;     /* ulozime nacteny znak */
                    char_count++;
                }
            }
        }
    }

    /* uzavreni souboru */
    fclose(f_p);
}
