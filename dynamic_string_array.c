#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_string_array.h"

/*
 * ------------------------------------------------------------------------------------
 * Nainicializuje dynamicke pole na jeho pocatecni velikost.
 * Vraci 1 (uspech) nebo 0 (neuspech).
 * ------------------------------------------------------------------------------------
 */
int init_array(dynamic_string_array *a) {
    if(!a) {        /* pointer na dynamicke pole ma hodnotu NULL */
        return 0;
    }

    a->size = INIT_ARRAY_SIZE;
    a->used = 0;
    a->array = NULL;

    a->array = calloc(INIT_ARRAY_SIZE, sizeof(char*));

    if(!a->array) {     /* nepodarilo se alokovat pamet */
        return 0;
    }

    return 1;
}

/*
 * ------------------------------------------------------------------------------------
 * Prida do dynamickeho pole novy retezec.
 * Vraci 1 (uspech) nebo 0 (neuspech).
 * ------------------------------------------------------------------------------------
 */
int add_to_array(dynamic_string_array *a, char *string) {
    char **tmp = NULL;     /* pointer na novy alokovany blok pameti */
    char *string_trimmed = NULL;     /* oriznute slovo */

    if(!a || !string) {     /* pointery maji hodnotu NULL */
        return 0;
    }

    string_trimmed = calloc(MAX_STRING_LENGTH, sizeof(char));
    if(!string_trimmed) {
        return 0;
    }

    if(a->size == a->used) {    /* dynamicke pole je plne, zvetsi se o konstantu INIT_ARRAY_SIZE */
        tmp = realloc(a->array,(a->size + INIT_ARRAY_SIZE) * sizeof(char*));

        if(!tmp) {      /* nepodarilo se realokovat pamet */
            free(string_trimmed);
            return 0;
        }
        else {   /* tmp neni NULL - podarilo se realokovat pamet */
            a->array = tmp;
            a->size += INIT_ARRAY_SIZE;
        }
    }

    /* alokace pameti pro novy string */
    a->array[a->used] = NULL;
    a->array[a->used] = calloc(MAX_STRING_LENGTH, sizeof(char));

    if(!a->array[a->used]) {
        free(string_trimmed);
        return 0;
    }

    strncpy(string_trimmed, string, MAX_STRING_LENGTH - 2);     /* oriznuti prilis dlouheho retezce */
    string_trimmed[MAX_STRING_LENGTH - 1] = '\0';

    strcpy(a->array[a->used], string_trimmed);  /* pridani retezce do dynamickeho pole */
    a->used++;

    free(string_trimmed);

    return 1;
}

/*
 * ------------------------------------------------------------------------------------
 * Uvolni pamet alokovanou pro dynamicke pole.
 * ------------------------------------------------------------------------------------
 */
void free_array(dynamic_string_array *a) {
    int i;

    if(a) {     /* pointer neni NULL */
        for(i = 0; i < a->used; i++) {
            free(a->array[i]);
        }

        free(a->array);
        free(a);
    }
}

/*
 * ------------------------------------------------------------------------------------
 * Vypise obsah dynamickeho pole do konzole.
 * ------------------------------------------------------------------------------------
 */
void print_array(dynamic_string_array *a) {
    int i;

    if(!a) {
        return;
    }

    for(i = 0; i < a->used; i++) {
        printf("%s\n", a->array[i]);
    }
}
