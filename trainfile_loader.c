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
    char *separator = NULL;     /* oddelovac v ceste k souboru */

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
        free(file_name);
        return 0;
    }

    /* oddelovac v ceste k souboru je zavisly na platforme */
#ifdef _WIN32
    separator = "\\";
#else
    separator = "/";
#endif


    for(i = 1; i <= file_count; i++) {
        /* vytvoreni nazvu trenovaciho souboru */
        sprintf(file_name, "%s%s%s%d%s", "data", separator, file_name_pattern, i, ".txt");

        errno = 0;      /* vynulovani globalni promenne errno */
        f_p = fopen(file_name, "r");

        if(!f_p) {      /* soubor se nepodarilo otevrit */
            printf("Error while opening file %s: %s\n", file_name, strerror(errno));
            free(file_name);
            free(string);
            return 0;
        }
        else {
            while(1) {
                c = fgetc(f_p);     /* nacteni dalsiho znaku */

                if(ferror(f_p)) {   /* pri I/O operaci s proudem stream doslo k chybe */
                    printf("Error while reading file %s: %d\n", file_name, ferror(f_p));
                    clearerr(f_p);  /* vynulovani chyby ve stavove strukture FILE */
                    free(file_name);
                    free(string);
                    fclose(f_p);
                    return 0;
                }

                if(feof(f_p)) {     /* dosli jsme na konec souboru */
                    break;
                }

                if((char)c == ' ') {      /* ukonceni slova */
                    string[char_count] = '\0';
                    (*word_count)++;

                    /*
                     * do hash tabulky pro vsechny soubory pridame aktualni slovo
                     * pokud uz v ni slovo je, pouze se zvetsi jeho count
                     */
                    if(!insert_string_to_hashtable(hashtable_all_files, string)) {
                        /* nepovedlo se vlozit slovo */
                        free(file_name);
                        free(string);
                        fclose(f_p);
                        return 0;
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

        /* uzavreni souboru */
        errno = 0;
        fclose(f_p);
        if(errno) {     /* globalni promenna errno neni nulova - doslo k chybe */
            printf("Error while closing file %s: %s\n", file_name, strerror(errno));
            return 0;
        }
    }

    free(file_name);
    file_name = NULL;
    free(string);
    string = NULL;

    return 1;
}
