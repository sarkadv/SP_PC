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
    char (*array)[MAX_STRING_LENGTH];       /* pole ukazatelu na char = pole retezcu */
    int size;   /* kapacita pole */
    int used;   /* pocet retezcu v poli */
} dynamic_string_array;

/*
 * ------------------------------------------------------------------------------------
 * Nainicializuje dynamicke pole na jeho pocatecni velikost.
 * ------------------------------------------------------------------------------------
 */
void init_array(dynamic_string_array *a);

/*
 * ------------------------------------------------------------------------------------
 * Prida do dynamickeho pole novy retezec.
 * ------------------------------------------------------------------------------------
 */
void add_to_array(dynamic_string_array *a, char *string);

/*
 * ------------------------------------------------------------------------------------
 * Vypise obsah dynamickeho pole do konzole.
 * ------------------------------------------------------------------------------------
 */
void print_array(dynamic_string_array *a);

#endif
