#ifndef SP_PC_EVAL_H
#define SP_PC_EVAL_H
#include "word_hashtable.h"

#define TEST_FILE_NAME_LENGTH 30    /* maximalni delka nazvu testovaciho souboru */


/*
 * ------------------------------------------------------------------------------------
 * Klasifikuje testovaci soubory (nazvy podle vzoru z prikazove radky) jako spam nebo ham.
 * Pro kazdy soubor jsou do dynamickeho pole ulozena vsechna se v nem vyskytujici slova.
 * Pomoci slov v dynamickem poli a slovniku je urcena pravdepodobnejsi trida (spam / ham).
 * Vraci 1 (uspech) nebo 0 (neuspech).
 * ------------------------------------------------------------------------------------
 */
int classify_test_files(word *dictionary[], char results[], char *file_name_pattern, int file_count, double spam_file_probability, double ham_file_probability);

#endif
