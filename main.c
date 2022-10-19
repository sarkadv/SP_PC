#include <stdio.h>
#include <stdlib.h>

#define ARG_COUNT 8

typedef struct {
    char** array;
    int size;
    int used;
} dynamic_size_array;

void print_err() {
    printf("Wrong parameters!\n");
    printf("Usage: \n");
    printf("<program name.exe> <spam train file name pattern> <spam train file count > 0> "
           "<ham train file name pattern> <ham train file count > 0> <test file name pattern> "
           "<test file count > 0> <output file name>");
}

int main(int argc, char* argv[]) {
    if(argc < ARG_COUNT) {
        print_err();
        return EXIT_FAILURE;
    }
    char* spam_train_file_name_pattern = argv[1];
    int spam_count = atoi(argv[2]); // atoi() vrati 0 pro neciselne retezce
    if(spam_count < 1) {    // neciselny retezec nebo 0 trenovacich souboru pro spam
        print_err();
        return EXIT_FAILURE;
    }

    char* ham_train_file_name_pattern = argv[3];
    int ham_count = atoi(argv[4]);
    if(ham_count < 1) {
        print_err();
        return EXIT_FAILURE;
    }

    char* test_file_name_pattern = argv[5];
    int test_count = atoi(argv[6]);
    if(test_count < 1) {
        print_err();
        return EXIT_FAILURE;
    }

    char* output_file_name = argv[7];

    return EXIT_SUCCESS;
}


