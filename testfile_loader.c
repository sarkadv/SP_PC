#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testfile_loader.h"
#include "dynamic_string_array.h"

void load_strings_to_array(dynamic_string_array *array, char *file_name) {
    int i;
    FILE *f_p = NULL;  // pointer na soubor
    char c; // posledni nacteny znak
    int char_count = 0; // pocet nactenych znaku v poslednim retezci
    char *string = malloc(MAX_STRING_LENGTH);   // posledni nacteny retezec

    f_p = fopen(file_name, "r");

    if(!f_p) {
        printf("cant load file");
    }
    else {
        while((c = fgetc(f_p)) != EOF) {
            if(c == ' ') {
                string[char_count] = '\0';
                add_to_array(array, string);

                free(string);
                string = malloc(MAX_STRING_LENGTH);
                char_count = 0;
            }
            else {
                string[char_count] = c;
                char_count++;
            }
        }
    }

    fclose(f_p);
}
