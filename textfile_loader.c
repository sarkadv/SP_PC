#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_string_array.h"
#include "textfile_loader.h"

void load_strings_to_array(dynamic_string_array *a, char *file_name_pattern, int file_count) {
    int i;
    FILE *f_p;  // pointer na soubor
    char *file_name = malloc(20);
    char c; // posledni nacteny znak
    int char_count = 0; // pocet nactenych znaku v poslednim retezci
    char *string = malloc(30);   // posledni nacteny retezec

    for(i = 1; i <= file_count; i++) {
        sprintf(file_name, "%s%s%d%s", "train/", file_name_pattern, i, ".txt");

        f_p = fopen(file_name, "r");

        if(!f_p) {
            printf("cant load file");
        }
        else {
            while((c = fgetc(f_p)) != EOF) {
                if(c == ' ') {
                    string[char_count] = '\0';
                    add_to_array(a, string);
                    free(string);
                    string = malloc(30);
                    char_count = 0;
                }
                else {
                    string[char_count] = c;
                    char_count++;
                }
            }
        }
    }

    fclose(f_p);

    print_array(a);
}
