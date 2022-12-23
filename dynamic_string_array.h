#ifndef SP_PC_DYNAMIC_STRING_ARRAY_H
#define SP_PC_DYNAMIC_STRING_ARRAY_H

#define INIT_ARRAY_SIZE 200     /* pocatecni velikost pole */
#define MAX_STRING_LENGTH 80   /* maximalni delka textoveho retezce ukladaneho do pole */

/*
 * ------------------------------------------------------------------------------------
 * Struktura pro dynamicky se zvetsujici pole.
 * ------------------------------------------------------------------------------------
 */
typedef struct {
    char (*array)[MAX_STRING_LENGTH];       /* pole textovych retezcu */
    int size;   /* kapacita pole */
    int used;   /* pocet retezcu v poli */
} dynamic_string_array;

/*
 * ------------------------------------------------------------------------------------
 * Nainicializuje dynamicke pole na jeho pocatecni velikost.
 * Vraci 1 (uspech) nebo 0 (neuspech).
 * ------------------------------------------------------------------------------------
 */
int init_array(dynamic_string_array *a);

/*
 * ------------------------------------------------------------------------------------
 * Prida do dynamickeho pole novy retezec.
 * Vraci 1 (uspech) nebo 0 (neuspech).
 * ------------------------------------------------------------------------------------
 */
int add_to_array(dynamic_string_array *a, char *string);

/*
 * ------------------------------------------------------------------------------------
 * Vypise obsah dynamickeho pole do konzole.
 * ------------------------------------------------------------------------------------
 */
void print_array(dynamic_string_array *a);

/*
 * ------------------------------------------------------------------------------------
 * Uvolni pamet alokovanou pro dynamicke pole.
 * ------------------------------------------------------------------------------------
 */
void free_array(dynamic_string_array *a);

#endif
