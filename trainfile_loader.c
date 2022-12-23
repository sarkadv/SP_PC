#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "trainfile_loader.h"
#include "word_hashtable.h"

/*
 * ------------------------------------------------------------------------------------
 * Nacte slova z testovaciho souboru a ulozi je do hash tabulky jako struktury word.
 * Vysledkem bude hash tabulka predana jako parametr hashtable_all_files.
 * Zaroven jsou spocitana vsechna nactena slova a tento pocet je ulozen do word_count.
 * Vraci 1 (uspech) nebo 0 (neuspech).
 * ------------------------------------------------------------------------------------
 */
int load_strings_to_hashtable(word *hashtable_all_files[], char *file_name_pattern, int file_count, int *word_count) {
    int i;
    FILE *f_p = NULL;       /* pointer na soubor */
    char *file_name = NULL;     /* nazev trenovaciho souboru */
    int c;       /* posledni nacteny znak */
    int char_count = 0;         /* pocet nactenych znaku v poslednim retezci */
    char *string = NULL;   /* posledni nacteny retezec */
    word *hashtable_one_file[HASHTABLE_SIZE];      /* hash tabulka pro jeden trenovaci soubor */

    if(!hashtable_all_files || !file_name_pattern || file_count <= 0 || !word_count) {
        /* pointery na NULL nebo nesmyslne ciselne hodnoty */
        return 0;
    }

    file_name = malloc(TRAIN_FILE_NAME_LENGTH);
    if(!file_name) {    /* nepodarila se alokace pameti */
        return 0;
    }

    string = malloc(MAX_STRING_LENGTH);
    if(!string) {       /* nepodarila se alokace pameti */
        return 0;
    }

    for(i = 1; i <= file_count; i++) {
        /* vytvoreni nazvu trenovaciho souboru */
        sprintf(file_name, "%s%s%d%s", "train/", file_name_pattern, i, ".txt");

        if(!init_hashtable(hashtable_one_file)) {   /* nepodarilo se nainicializovat hash tabulku */
            return 0;
        }

        errno = 0;      /* vynulovani globalni promenne errno */
        f_p = fopen(file_name, "r");

        if(!f_p) {      /* soubor se nepodarilo otevrit */
            printf("Error while opening file: %s\n", strerror(errno));
            return 0;
        }
        else {
            while(1) {
                c = fgetc(f_p);     /* nacteni dalsiho znaku */

                if(feof(f_p)) {     /* dosli jsme na konec souboru */
                    break;
                }

                if((char)c == ' ') {      /* ukonceni slova */
                    string[char_count] = '\0';
                    (*word_count)++;

                    if(!find_by_key(hashtable_one_file, string)) {   /* slovo se v tomto souboru jeste nevyskytlo */
                        /* do hash tabulky pro tento soubor pridame aktualni slovo */
                        if(!insert_string_to_hashtable(hashtable_one_file, string)) {
                            /* nepovedlo se vlozit slovo */
                            return 0;
                        }

                        /* do hash tabulky pro vsechny soubory pridame aktualni slovo */
                        if(!insert_string_to_hashtable(hashtable_all_files, string)) {
                            /* nepovedlo se vlozit slovo */
                            return 0;
                        }
                    }

                    /* zacneme nacitat dalsi slovo - reset promennych */
                    free(string);
                    string = NULL;
                    string = malloc(MAX_STRING_LENGTH);
                    char_count = 0;
                }
                else {      /* jeste jsme nedosli na konec slova */
                    string[char_count] = (char)c;     /* ulozime nacteny znak */
                    char_count++;
                }
            }
        }
    }

    free(file_name);
    file_name = NULL;
    free(string);
    string = NULL;

    /* uzavreni souboru */
    errno = 0;
    fclose(f_p);
    if(errno) {     /* globalni promenna errno neni nulova - doslo k chybe */
        printf("Error while closing file: %s\n", strerror(errno));
        return 0;
    }

    return 1;
}
