#include <stdio.h>
#include <stdlib.h>
#include "err.h"
#include "textfile_loader.h"
#include "word_hashtable.h"

#define ARG_COUNT 8

// spoji hashtable pro spam a ham do jedne hashtabulky
// vysledek je ve spamove hashtabulce
// vraci pocet slov ve slovniku
int merge_hashtables(word *hashtable_spam[], word *hashtable_ham[]) {
    int words_count = 0;
    int i;
    // nastaveni cetnosti spamovych slov v tabulce pro spam
    // count se vypocital pri cteni souboru
    for(i = 0; i < HASHTABLE_SIZE; i++) {
        word *item = hashtable_spam[i];

        while(item) {
            item->spam_count = item->count;
            words_count++;

            item = item->next;
        }
    }

    // nastaveni cetnosti hamovych slov v tabulce pro ham
    // a pridani slov do hashtabulky pro spam
    for(i = 0; i < HASHTABLE_SIZE; i++) {
        word *item = hashtable_ham[i];

        while(item) {   // dokud na indexu i je nejake slovo
            word *found = find_by_key(hashtable_spam, item->string);    // zkusime najit hamove slovo i ve spamove tabulce

            if (found) {   // jestlize je hamove slovo i ve spamove tabulce
                found->ham_count = item->count;
            }
            else {
                found = insert_string_to_hashtable(hashtable_spam, item->string);
                found->spam_count = 0;
                found->ham_count = item->count;
                words_count++;
            }

            item = item->next;
        }
    }

    return words_count;

}

void compute_probabilities(word *hashtable[], int dictionary_size) {
    int i;
    for(i = 0; i < HASHTABLE_SIZE; i++) {
        word *item = hashtable[i];

        while(item) {
            item->spam_probability = (item->spam_count + 1) / (double)(item->spam_count + dictionary_size);
            item->ham_probability = (item->ham_count + 1) / (double)(item->ham_count + dictionary_size);

            item = item->next;
        }
    }
}

int main(int argc, char *argv[]) {
    char *spam_train_file_name_pattern;
    int spam_count;
    int ham_count;
    char *test_file_name_pattern;
    int test_count;
    char *output_file_name;
    char *ham_train_file_name_pattern;
    double spam_file_probability;
    double ham_file_probability;
    int dictionary_size;
    char *results;

    if(argc < ARG_COUNT) {
        print_err_number_parameters();
        return EXIT_FAILURE;
    }
    spam_train_file_name_pattern = argv[1];
    spam_count = atoi(argv[2]); // atoi() vrati 0 pro neciselne retezce
    if(spam_count < 1) {    // neciselny retezec nebo 0 trenovacich souboru pro spam
        print_err_spam_count();
        return EXIT_FAILURE;
    }

    ham_train_file_name_pattern = argv[3];
    ham_count = atoi(argv[4]);
    if(ham_count < 1) {
        print_err_ham_count();
        return EXIT_FAILURE;
    }

    spam_file_probability = (double)spam_count / (spam_count + ham_count);
    ham_file_probability = (double)ham_count / (spam_count + ham_count);

    test_file_name_pattern = argv[5];
    test_count = atoi(argv[6]);
    if(test_count < 1) {
        print_err_test_count();
        return EXIT_FAILURE;
    }

    output_file_name = argv[7];

    word *hashtable_spam[HASHTABLE_SIZE];
    init_hashtable(hashtable_spam);
    load_strings_to_hashtable(hashtable_spam, spam_train_file_name_pattern, spam_count);

    word *hashtable_ham[HASHTABLE_SIZE];
    init_hashtable(hashtable_ham);
    load_strings_to_hashtable(hashtable_ham, ham_train_file_name_pattern, ham_count);

    dictionary_size = merge_hashtables(hashtable_spam, hashtable_ham);
    compute_probabilities(hashtable_spam, dictionary_size);
    print_hashtable(hashtable_spam);

    results = malloc(sizeof(char) * test_count);
    

    return EXIT_SUCCESS;
}


