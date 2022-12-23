#include <stdio.h>
#include "err.h"

void print_err_number_parameters() {
    printf("Wrong number of parameters!\n");
    printf("There has to be 8 parameters - name of the program and 7 others.");
    printf("Usage: \n");
    printf("<program name.exe> <spam train file name pattern> <spam train file count> "
           "<ham train file name pattern> <ham train file count> <test file name pattern> "
           "<test file count> <output file name>");
}

void print_err_spam_count() {
    printf("Wrong parameters!");
    printf("Spam training file count has to be > 0.\n");
}

void print_err_ham_count() {
    printf("Wrong parameters!");
    printf("Ham training file count has to be > 0.\n");
}

void print_err_test_count() {
    printf("Wrong parameters!");
    printf("Testing file count has to be > 0.\n");
}

void print_err_dictionary() {
    printf("Error while creating the dictionary! (function merge_hashtables() in main.c)\n");
}

void print_err_probabilities() {
    printf("Error while counting spam and ham probabilities! (function compute_probabilities() in main.c)\n");
}

void print_err_classify() {
    printf("Error while classifying test files! (function classify_test_files() in eval.c)\n");
}

void print_err_init_hashtable() {
    printf("Error while initializing hashtable! (function init_hashtable() in word_hashtable.c)\n");
}

void print_err_load_strings_hashtable() {
    printf("Error while loading strings from file to hashtable! (function load_strings_to_hashtable() in trainfile_loader.c)\n");
}

void print_err_save_results() {
    printf("Error while saving results to file! (function print_results_to_file() in output.c)\n");
}
