#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "dynamic_string_array.h"
#include "testfile_loader.h"
#include "eval.h"
#include "word_hashtable.h"

/*
 * ------------------------------------------------------------------------------------
 * Pomoci predaneho slovniku a dynamickeho pole zjisti, ktera slova z pole se nachazi
 * zaroven ve slovniku.
 * Tato slova umistuje do pole found_words.
 * Vrati pocet techto slov / v pripade neuspechu -1.
 * ------------------------------------------------------------------------------------
 */
int find_dictionary_words(word *dictionary[], dynamic_string_array *array, word *found_words[]) {
    int found_words_count = 0;      /* pocet slov, ktera jsou zaroven v dynamickem poli i ve slovniku */
    int i;
    word *found = NULL;     /* nalezene slovo ve slovniku - pokud ve slovniku neni, je NULL */

    if(!dictionary || !array || !found_words) {
        return -1;
    }

    for(i = 0; i < array->used; i++) {
        found = find_by_key(dictionary, array->array[i]);

        if(found) {     /* slovo bylo nalezeno ve slovniku */
            found_words[found_words_count] = found;
            found_words_count++;
        }
    }

    return found_words_count;
}

/*
 * ------------------------------------------------------------------------------------
 * Zjisti, zda je pravdepodobnejsi, ze je soubor spam nebo ham podle
 * pravdepodobnosti slov ve slovniku.
 * Pro vsechna slova testovaciho souboru, ktera jsou ve slovniku, jsou vypocteny obe
 * pravdepodobnosti (spam i ham).
 * Pravdepodobnosti se scitaji pres vsechna slova.
 * Pote je vraceno 'S' nebo 'H', podle toho, zda je suma pravdepodobnosti spamu vetsi nez
 * suma pravdepodobnosti hamu, nebo naopak.
 * V pripade neuspechu je vraceno '0'.
 * ------------------------------------------------------------------------------------
 */
char argmax(word *found_words[], int found_words_count, double spam_file_probability, double ham_file_probability) {
    double spam_result = 0;     /* suma pravdepodobnosti spamu */
    double ham_result = 0;      /* suma pravdepodobnosti hamu */
    int i;

    if(!found_words || found_words_count <= 0 || spam_file_probability <= 0 || ham_file_probability <= 0) {
        return '0';
    }

    for(i = 0; i < found_words_count; i++) {
        errno = 0;  /* nutne vynulovat globalni promennou errno */
        spam_result += log10(found_words[i]->spam_probability);
        if(errno) {     /* globalni promenna errno nema hodnotu 0, tedy doslo k chybe */
            printf("Error while computing the common logarithm: %s\n", strerror(errno));
            return '0';
        }

        errno = 0;
        ham_result += log10(found_words[i]->ham_probability);
        if(errno) {
            printf("Error while computing the common logarithm: %s\n", strerror(errno));
            return '0';
        }
    }

    /* vynasobeni pravdepodobnosti vyskytu tridy v datech */
    spam_result = spam_result * spam_file_probability;
    ham_result = ham_result * ham_file_probability;

    return spam_result > ham_result ? 'S' : 'H';
}

/*
 * ------------------------------------------------------------------------------------
 * Klasifikuje jeden testovaci soubor jako spam nebo ham.
 * Do pole se ulozi vsechna slova, ktera se nachazi v testovacim souboru a jsou
 * ve slovniku.
 * Pomoci techto slov a funkce argmax() je pote stanoven vysledek.
 * Vraci 'S' (Spam) nebo 'H' (Ham) v pripade uspechu, '0' jinak.
 * ------------------------------------------------------------------------------------
 */
char classify_test_file(word *dictionary[], dynamic_string_array *array, double spam_file_probability, double ham_file_probability) {
    char result;          /* pismeno tridy (H nebo S) */
    word **found_words;     /* slova testovaciho souboru, ktera jsou ve slovniku */
    int found_words_count;    /* pocet slov testovaciho souboru, ktera jsou ve slovniku */

    if(!dictionary || !array || spam_file_probability <= 0 || ham_file_probability <= 0) {
        return '0';
    }

    found_words = malloc(array->used * sizeof(word*));

    /* nalezeni slov testovaciho souboru, ktera jsou zaroven ve slovniku */
    found_words_count = find_dictionary_words(dictionary, array, found_words);

    if(found_words_count < 0) {     /* funkce find_dictionary_words dostala nespravne parametry */
        return '0';
    }

    /* zjisteni, zda je soubor spam nebo ham podle slov ve slovniku */
    result = argmax(found_words, found_words_count, spam_file_probability, ham_file_probability);

    free(found_words);
    found_words = NULL;

    return result;
}

/*
 * ------------------------------------------------------------------------------------
 * Klasifikuje testovaci soubory (nazvy podle vzoru z prikazove radky) jako spam nebo ham.
 * Pro kazdy soubor jsou do dynamickeho pole ulozena vsechna se v nem vyskytujici slova.
 * Pomoci slov v dynamickem poli a slovniku je urcena pravdepodobnejsi trida (spam / ham).
 * Vraci 1 (uspech) nebo 0 (neuspech).
 * ------------------------------------------------------------------------------------
 */
int classify_test_files(word *dictionary[], char results[], char *file_name_pattern, int file_count, double spam_file_probability, double ham_file_probability) {
    int i;
    char file_name[TEST_FILE_NAME_LENGTH];     /* jmeno konkretniho testovaciho souboru */
    dynamic_string_array *array;    /* dynamicke pole pro slova z testovaciho souboru */

    if(!dictionary || !results || !file_name_pattern || file_count <= 0 || spam_file_probability <= 0 || ham_file_probability <= 0) {
        /* pointery ukazuji na NULL nebo ciselne hodnoty jsou nesmyslne */
        return 0;
    }

    for(i = 0; i < file_count; i++) {
        array = malloc(sizeof(dynamic_string_array*));

        if(!array) {
            return 0;
        }

        if(!init_array(array)) {
            return 0;
        }

        /* vytvoreni jmena konkretniho souboru */
        sprintf(file_name, "%s%s%d%s", "test/", file_name_pattern, (i + 1), ".txt");

        /* nacteni slov ze souboru do dynamickeho pole */
        if(!load_strings_to_array(array, file_name)) {
            return 0;   /* slova se nepodarilo nacist */
        }

        /* klasifikace souboru - na dany index se do pole results da znak 'S' nebo 'H' */
        results[i] = classify_test_file(dictionary, array, spam_file_probability, ham_file_probability);
        /* v pripade neuspechu je ulozeno na index i '0' */

        free_array(array);
        array = NULL;
    }

    return 1;

}
