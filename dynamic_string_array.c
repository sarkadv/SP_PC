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

    a->array = malloc(INIT_ARRAY_SIZE * sizeof(char[MAX_STRING_LENGTH]));

    if(!a->array) {     /* nepodarilo se alokovat pamet */
        return 0;
    }

    a->size = INIT_ARRAY_SIZE;
    a->used = 0;

    return 1;
}

/*
 * ------------------------------------------------------------------------------------
 * Prida do dynamickeho pole novy retezec.
 * Vraci 1 (uspech) nebo 0 (neuspech).
 * ------------------------------------------------------------------------------------
 */
int add_to_array(dynamic_string_array *a, char *string) {
    char (*tmp)[MAX_STRING_LENGTH];     /* pointer na novy alokovany blok pameti */

    if(!a || !string) {     /* pointery maji hodnotu NULL */
        return 0;
    }

    if(a->size == a->used) {    /* dynamicke pole je plne, zvetsi se o konstantu INIT_ARRAY_SIZE */
        tmp = realloc(a->array,(a->size + INIT_ARRAY_SIZE) * sizeof(char[MAX_STRING_LENGTH]));

        if(!tmp) {      /* nepodarilo se realokovat pamet */
            return 0;
        }
        else {   /* tmp neni NULL - podarilo se realokovat pamet */
            a->array = tmp;
            a->size += INIT_ARRAY_SIZE;
        }
    }

    strcpy(a->array[a->used], string);  /* pridani retezce do dynamickeho pole */
    a->used++;

    return 1;
}

/*
 * ------------------------------------------------------------------------------------
 * Uvolni pamet alokovanou pro dynamicke pole.
 * ------------------------------------------------------------------------------------
 */
void free_array(dynamic_string_array *a) {
    if(a) {     /* pointer neni NULL */
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
