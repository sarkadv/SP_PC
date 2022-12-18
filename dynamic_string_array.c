#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_string_array.h"

/*
 * ------------------------------------------------------------------------------------
 * Nainicializuje dynamicke pole na jeho pocatecni velikost.
 * ------------------------------------------------------------------------------------
 */
void init_array(dynamic_string_array *a) {
    a->array = malloc(INIT_ARRAY_SIZE * sizeof(char[MAX_STRING_LENGTH]));
    a->size = INIT_ARRAY_SIZE;
    a->used = 0;
}

/*
 * ------------------------------------------------------------------------------------
 * Prida do dynamickeho pole novy retezec.
 * ------------------------------------------------------------------------------------
 */
void add_to_array(dynamic_string_array *a, char *string) {
    if(a->size == a->used) {    /* dynamicke pole je plne, zvetsi se o konstantu INIT_ARRAY_SIZE */
        char(*tmp)[MAX_STRING_LENGTH] = realloc(a->array,
                                                (a->size + INIT_ARRAY_SIZE) * sizeof(char[MAX_STRING_LENGTH]));

        if(tmp) {   /* tmp neni NULL - podarilo se realokovat pamet */
            a->array = tmp;
            a->size *= 2;
        }
    }

    strcpy(a->array[a->used], string);  /* pridani retezce do dynamickeho pole */
    a->used++;
}

/*
 * ------------------------------------------------------------------------------------
 * Vypise obsah dynamickeho pole do konzole.
 * ------------------------------------------------------------------------------------
 */
void print_array(dynamic_string_array *a) {
    int i;

    for(i = 0; i < a->used; i++) {
        printf("%s\n", a->array[i]);
    }
}