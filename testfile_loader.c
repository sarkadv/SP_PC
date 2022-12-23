#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "testfile_loader.h"
#include "dynamic_string_array.h"

/*
 * ------------------------------------------------------------------------------------
 * Nacte slova z testovaciho souboru a ulozi je do dynamickeho pole.
 * Vraci 1 (uspech) nebo 0 (neuspech).
 * ------------------------------------------------------------------------------------
 */
int load_strings_to_array(dynamic_string_array *array, char *file_name) {
    FILE *f_p = NULL;       /* pointer na soubor */
    int c;             /* posledni nacteny znak */
    int char_count = 0;     /* pocet nactenych znaku v poslednim retezci */
    char *string = NULL;       /* posledni nacteny retezec */

    if(!array || !file_name) {
        return 0;
    }

    string = malloc(MAX_STRING_LENGTH);
    if(!string) {   /* nepodarilo se alokovat pamet */
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

            if(ferror(f_p)) {   /* pri I/O operaci s proudem stream doslo k chybe */
                printf("Error while reading file: %d\n", ferror(f_p));
                clearerr(f_p);  /* vynulovani chyby ve stavove strukture FILE */
                return 0;
            }

            if(feof(f_p)) {     /* dosli jsme na konec souboru */
                break;
            }

            if((char)c == ' ') {      /* ukonceni slova */
                string[char_count] = '\0';
                if(!add_to_array(array, string)) {       /* pridame cele slovo do dynamickeho pole */
                    return 0;             /* slovo se nepodarilo pridat */
                }

                /* zacneme nacitat dalsi slovo - reset promennych */
                free(string);
                string = NULL;
                string = malloc(MAX_STRING_LENGTH);

                if(!string) {   /* nepodarilo se alokovat pamet pro nove slovo */
                    return 0;
                }

                char_count = 0;
            }
            else {      /* jeste jsme nedosli na konec slova */
                string[char_count] = (char)c;     /* ulozime nacteny znak */
                char_count++;
            }
        }
    }

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
