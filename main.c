#include <stdlib.h>
#include "err.h"
#include "trainfile_loader.h"
#include "word_hashtable.h"
#include "eval.h"
#include "output.h"

#define ARG_COUNT 8             /* celkovy pocet parametru prikazove radky */

/* indexy parametru v poli stringu (uzivatelsky vstup z prikazove radky) */
#define ARG_SPAM_PATTERN 1
#define ARG_SPAM_COUNT 2
#define ARG_HAM_PATTERN 3
#define ARG_HAM_COUNT 4
#define ARG_TEST_PATTERN 5
#define ARG_TEST_COUNT 6
#define ARG_OUTPUT 7

/*
 * ------------------------------------------------------------------------------------
 * Metoda spoji hash tabulku pro spam a ham do jedine hash tabulky.
 * Vraci pocet slov ve slovniku (spojene hash tabulce).
 * ------------------------------------------------------------------------------------
 */
int merge_hashtables(word *hashtable_spam[], word *hashtable_ham[]) {
    int words_count = 0;        /* pocitadlo pro celkovy pocet rozdilnych slov v konecnem slovniku */
    int i;
    word *item = NULL;          /* aktualne vybrane slovo z hash tabulky */
    word *found = NULL;         /* hamove slovo nalezene ve spamove hash tabulce */

    /*
     * nastaveni cetnosti spamovych slov v tabulce pro spam
     * count se vypocital pri cteni souboru
     */
    for(i = 0; i < HASHTABLE_SIZE; i++) {
        item = hashtable_spam[i];

        while(item) {
            item->spam_count = item->count;
            words_count++;

            item = item->next;
        }
    }

    /*
     * nastaveni cetnosti hamovych slov v tabulce pro ham,
     * pridani slov do hashtabulky pro spam
     */
    for(i = 0; i < HASHTABLE_SIZE; i++) {
        item = hashtable_ham[i];

        while(item) {   /* dokud na indexu i je nejake slovo */
            found = find_by_key(hashtable_spam, item->string);    /* zkusime najit hamove slovo i ve spamove tabulce */

            if (found) {   /* jestlize je hamove slovo i ve spamove tabulce */
                found->ham_count = item->count;
            }
            else {      /* hamove slovo neni ve spamove tabulce */
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

/*
 * ------------------------------------------------------------------------------------
 * Metoda vypocita pravdepodobnosti kazdeho slova, ze se jedna o spam nebo o ham.
 * Pravdepodobnosti jsou ukladany primo do struktury word.
 * ------------------------------------------------------------------------------------
 */
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

/*
 * ------------------------------------------------------------------------------------
 * Vstupni funkce programu.
 * Postara se o vyber dat z prikazove radky, nacteni a vyhodnoceni trenovacich souboru.
 * Pote jsou nacteny a klasifikovany testovaci soubory,
 * nakonec jsou vysledky ulozeny do textoveho souboru.
 * ------------------------------------------------------------------------------------
 */
int main(int argc, char *argv[]) {
    char *spam_train_file_name_pattern = NULL;      /* vzor pro nazev souboru s trenovacimi spamovymi emaily */
    char *ham_train_file_name_pattern = NULL;       /* vzor pro nazev souboru s trenovacimi hamovymi emaily */
    char *test_file_name_pattern = NULL;       /* vzor pro nazev souboru s testovacimi neklasifikovanymi emaily */
    char *output_file_name = NULL;        /* nazev souboru pro vysledky */
    char *results = NULL;               /* vysledky - pro kazdy soubor pismeno S (Spam) nebo H (Ham) */

    int spam_count;     /* pocet trenovacich spamovych souboru */
    int ham_count;      /* pocet trenovacich hamovych souboru */
    int test_count;     /* pocet testovacich neklasifikovanych souboru */
    int dictionary_size;    /* pocet polozek vysledneho slovniku */

    double spam_file_probability;   /* pravdepodobnost spamoveho souboru podle trenovacich souboru */
    double ham_file_probability;    /* pravdepodobnost hamoveho souboru podle trenovacich souboru */

    if(argc < ARG_COUNT) {
        print_err_number_parameters();
        return EXIT_FAILURE;
    }

    spam_train_file_name_pattern = argv[ARG_SPAM_PATTERN];

    spam_count = atoi(argv[ARG_SPAM_COUNT]);     /* atoi() vrati 0 pro neciselne retezce a cislo 0 */
    if(spam_count < 1) {            /* neciselny retezec nebo 0 trenovacich souboru pro spam */
        print_err_spam_count();
        return EXIT_FAILURE;
    }

    ham_train_file_name_pattern = argv[ARG_HAM_PATTERN];

    ham_count = atoi(argv[ARG_HAM_COUNT]);      /* atoi() vrati 0 pro neciselne retezce a cislo 0 */
    if(ham_count < 1) {             /* neciselny retezec nebo 0 trenovacich souboru pro ham */
        print_err_ham_count();
        return EXIT_FAILURE;
    }

    /* vypocet pravdepodobnosti typu souboru podle poctu trenovacich souboru */
    spam_file_probability = (double)spam_count / (spam_count + ham_count);
    ham_file_probability = (double)ham_count / (spam_count + ham_count);

    test_file_name_pattern = argv[ARG_TEST_PATTERN];

    test_count = atoi(argv[ARG_TEST_COUNT]);     /* atoi() vrati 0 pro neciselne retezce a cislo 0 */
    if(test_count < 1) {            /* neciselny retezec nebo 0 testovacich souboru */
        print_err_test_count();
        return EXIT_FAILURE;
    }

    output_file_name = argv[ARG_OUTPUT];

    /* inicializace a naplneni spamove hash tabulky */
    word *hashtable_spam[HASHTABLE_SIZE];
    init_hashtable(hashtable_spam);
    load_strings_to_hashtable(hashtable_spam, spam_train_file_name_pattern, spam_count);

    /* inicializace a naplneni hamove hash tabulky */
    word *hashtable_ham[HASHTABLE_SIZE];
    init_hashtable(hashtable_ham);
    load_strings_to_hashtable(hashtable_ham, ham_train_file_name_pattern, ham_count);

    /* spojeni hash tabulky pro spam a hash tabulky pro ham */
    dictionary_size = merge_hashtables(hashtable_spam, hashtable_ham);

    /* vypocet pravdepodobnosti, zda se jedna o spam / ham pro kazde slovo ve slovniku */
    compute_probabilities(hashtable_spam, dictionary_size);

    results = malloc(sizeof(char) * test_count);

    /*
     * klasifikace testovacich souboru - rozhodnuti, zda je kazdy soubor spam nebo ham
     * vysledky jsou ukladany do pole results, kde je pro kazdy soubor pismeno S (Spam) nebo H (Ham)
     */
    classify_test_files(hashtable_spam, results, test_file_name_pattern, test_count, spam_file_probability, ham_file_probability);

    /* vysledky ulozeny do textoveho souboru */
    print_results_to_file(results, test_count, test_file_name_pattern, output_file_name);

    return EXIT_SUCCESS;
}


