#include <stdio.h>
#include <stdlib.h>
#include "dynamic_string_array.h"
#include "err.h"
#include "textfile_loader.h"

#define ARG_COUNT 8

int main(int argc, char *argv[]) {
    if(argc < ARG_COUNT) {
        print_err_number_parameters();
        return EXIT_FAILURE;
    }
    char *spam_train_file_name_pattern = argv[1];
    int spam_count = atoi(argv[2]); // atoi() vrati 0 pro neciselne retezce
    if(spam_count < 1) {    // neciselny retezec nebo 0 trenovacich souboru pro spam
        print_err_spam_count();
        return EXIT_FAILURE;
    }

    char *ham_train_file_name_pattern = argv[3];
    int ham_count = atoi(argv[4]);
    if(ham_count < 1) {
        print_err_ham_count();
        return EXIT_FAILURE;
    }

    char *test_file_name_pattern = argv[5];
    int test_count = atoi(argv[6]);
    if(test_count < 1) {
        print_err_test_count();
        return EXIT_FAILURE;
    }

    char *output_file_name = argv[7];

    dynamic_string_array a;
    init_array(&a);
    load_strings_to_array(&a, spam_train_file_name_pattern, 2);

    return EXIT_SUCCESS;
}


