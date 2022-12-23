#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    char c;             /* posledni nacteny znak */
    int char_count = 0;     /* pocet nactenych znaku v poslednim retezci */
    char *string = malloc(MAX_STRING_LENGTH);       /* posledni nacteny retezec */

    f_p = fopen(file_name, "r");

    if(!f_p) {      /* soubor se nepodarilo otevrit */
        printf("The file %s couldn't be opened.\n", file_name);
        return 0;
    }
    else {
        while(1) {
            c = fgetc(f_p);     /* nacteni dalsiho znaku */

            if(feof(f_p)) {     /* dosli jsme na konec souboru */
                break;
            }

            if(c == ' ') {      /* ukonceni slova */
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
                string[char_count] = c;     /* ulozime nacteny znak */
                char_count++;
            }
        }
    }

    /* uzavreni souboru */
    fclose(f_p);

    return 1;
}
