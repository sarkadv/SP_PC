#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dynamic_string_array.h"
#include "testfile_loader.h"
#include "eval.h"
#include "word_hashtable.h"

int find_dictionary_words(word *dictionary[], dynamic_string_array *array, word *found_words[]) {
    int found_words_count = 0;
    int i;

    for(i = 0; i < array->used; i++) {
        word *found = find_by_key(dictionary, array->array[i]);

        if(found) {
            found_words[found_words_count] = found;
            found_words_count++;
        }
    }

    return found_words_count;
}

char argmax(word *found_words[], int found_words_count, double spam_file_probability, double ham_file_probability) {
    double spam_result = 0;
    double ham_result = 0;
    int i;

    for(i = 0; i < found_words_count; i++) {
        spam_result += log10(found_words[i]->spam_probability);
        ham_result += log10(found_words[i]->ham_probability);
    }

    spam_result = spam_result * spam_file_probability;
    ham_result = ham_result * ham_file_probability;

    return spam_result > ham_result ? 'S' : 'H';
}

char classify_test_file(word *dictionary[], dynamic_string_array *array, double spam_file_probability, double ham_file_probability) {
    char result;
    int found_words_count;
    word *found_words[array->used];

    found_words_count = find_dictionary_words(dictionary, array, found_words);

    result = argmax(found_words, found_words_count, spam_file_probability, ham_file_probability);
    return result;
}

void classify_test_files(word *dictionary[], char results[], char *file_name_pattern, int file_count, double spam_file_probability, double ham_file_probability) {
    int i;
    char *file_name;

    for(i = 0; i < file_count; i++) {
        dynamic_string_array array;
        init_array(&array);

        file_name = malloc(20);
        sprintf(file_name, "%s%s%d%s", "test/", file_name_pattern, (i + 1), ".txt");

        load_strings_to_array(&array, file_name);
        results[i] = classify_test_file(dictionary, &array, spam_file_probability, ham_file_probability);
    }

}
