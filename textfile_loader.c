#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "textfile_loader.h"
#include "word_hashtable.h"

void load_strings_to_hashtable(word *hashtable_all_files[], char *file_name_pattern, int file_count) {
    int i;
    FILE *f_p;  // pointer na soubor
    char *file_name = malloc(20);
    char c; // posledni nacteny znak
    int char_count = 0; // pocet nactenych znaku v poslednim retezci
    char *string = malloc(MAX_STRING_LENGTH);   // posledni nacteny retezec

    for(i = 1; i <= file_count; i++) {
        sprintf(file_name, "%s%s%d%s", "train/", file_name_pattern, i, ".txt");

        f_p = fopen(file_name, "r");

        word *hashtable_one_file[HASHTABLE_SIZE];       // hashtabulka pro jeden soubor
        init_hashtable(hashtable_one_file);

        if(!f_p) {
            printf("cant load file");
        }
        else {
            while((c = fgetc(f_p)) != EOF) {
                if(c == ' ') {
                    string[char_count] = '\0';

                    if(!find_by_key(hashtable_one_file, string)) {   // slovo se v tomto souboru jeste nevyskytlo
                        insert_string_to_hashtable(hashtable_one_file, string);
                        insert_string_to_hashtable(hashtable_all_files, string);
                    }

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
    }

    fclose(f_p);
}
