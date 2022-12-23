#ifndef SP_PC_TRAINFILE_LOADER_H
#define SP_PC_TRAINFILE_LOADER_H
#include "word_hashtable.h"

#define TRAIN_FILE_NAME_LENGTH 30    /* maximalni delka nazvu testovaciho souboru */

/*
 * ------------------------------------------------------------------------------------
 * Nacte slova z testovaciho souboru a ulozi je do hash tabulky jako struktury word.
 * Vysledkem bude hash tabulka predana jako parametr hashtable_all_files.
 * Zaroven jsou spocitana vsechna nactena slova a tento pocet je ulozen do word_count.
 * Vraci 1 (uspech) nebo 0 (neuspech).
 * ------------------------------------------------------------------------------------
 */
int load_strings_to_hashtable(word *hashtable_all_files[], char *file_name_pattern, int file_count, int *word_count);

#endif
