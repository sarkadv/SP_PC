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
