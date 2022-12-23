#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include "word_hashtable.h"

/*
 * ------------------------------------------------------------------------------------
 * Vrati hash pro dany retezec.
 * V pripade prilis dlouheho retezce vrati -1.
 * ------------------------------------------------------------------------------------
 */
int hash_code(char *string) {
    int length;   /* delka textoveho retezce */

    if(strlen(string) > (unsigned int)INT_MAX) {    /* delku neni mozne reprezentovat jako int */
        return -1;
    }
    else {
        length = (int)strlen(string);
    }

    int code = 0;       /* vypocitany hash */
    int i;

    for(i = length - 1; i >= 0; i--) {
        code += ((int)(string[i] * pow(31, (i + 1))) % HASHTABLE_SIZE);
    }

    code = code % HASHTABLE_SIZE;
    return code;
}

/*
 * ------------------------------------------------------------------------------------
 * Vlozi nove slovo do hash tabulky.
 * Vrati se struktura word reprezentujici dany textovy retezec (slovo).
 * Pokud se slovo nepodarilo vlozit, vrati se NULL.
 * ------------------------------------------------------------------------------------
 */
word* insert_string_to_hashtable(word *hashtable[], char *string) {
    word *item = NULL;  /* nalezene slovo v hash tabulce, je NULL pokud v tabulce dane slovo jeste neni */
    int hash_index;     /* vypocitany hash pro nove slovo */

    if(!hashtable || !string) {
        return NULL;
    }

    /* zjistime, zda slovo uz v hash tabulce je */
    item = find_by_key(hashtable, string);

    if(item) {    /* jestlize slovo uz v tabulce je (item neni NULL), nevlozi se znovu */
        item->count++;
    }
    else {      /* vytvori se nova struktura word, ktera se vlozi do hash tabulky */
        item = malloc(sizeof(word));

        if(!item) {     /* nepodarilo se alokovat pamet pro celou strukturu */
            return NULL;
        }

        item->string = malloc(MAX_STRING_LENGTH);

        if(!item->string) {     /* nepodarilo se alokovat pamet pro cast struktury */
            free(item);
            return NULL;
        }

        strcpy(item->string, string);
        item->count = 1;

        hash_index = hash_code(string);

        if(hash_index == -1) {      /* nepodarilo se vypocitat hash */
            return NULL;
        }

        if(hashtable[hash_index]) {     /* na indexu neni NULL - uz je tam nejake slovo,
                                         * nova struktura bude vlozena na jeho misto
                                         * a bude mit ukazatel next na puvodni slovo
                                         */
            item->next = hashtable[hash_index];

        }

        hashtable[hash_index] = item;
    }

    return item;

}

/*
 * ------------------------------------------------------------------------------------
 * Pokusi se najit v hash tabulce slovo podle jeho klice (textovy retezec slova).
 * Vrati bud nalezene slovo (struktura word) nebo NULL (slovo nebylo nalezeno).
 * ------------------------------------------------------------------------------------
 */
word* find_by_key(word *hashtable[], char *key) {
    int index;     /* hash pro dany klic */
    word *item;      /* slovo na indexu danem hash kodem */

    if(!hashtable || !key) {
        return NULL;
    }

    index = hash_code(key);
    item = hashtable[index];

    while(item) {   /* dokud pointer ukazuje na nejake slovo (neni NULL) */
        if(!strcmp(item->string, key)) {    /* strcmp() vrati 0, jestlize se retezce rovnaji, proto negace */
            return item;
        }
        item = item->next;
    }

    return NULL;
}

/*
 * ------------------------------------------------------------------------------------
 * Nainicializuje hash tabulku na jeji danou velikost HASHTABLE_SIZE, danou konstantou.
 * V pripade uspechu vraci 1, jinak 0.
 * ------------------------------------------------------------------------------------
 */
int init_hashtable(word *hashtable[]) {
    int i;

    if(!hashtable) {
        return 0;
    }

    for(i = 0; i < HASHTABLE_SIZE; i++) {
        hashtable[i] = NULL;
    }

    return 1;
}

/*
 * ------------------------------------------------------------------------------------
 * Uvolni pamet alokovanou pro hash tabulku.
 * ------------------------------------------------------------------------------------
 */
void free_hashtable(word *hashtable[]) {
    int i;
    word *item = NULL;  /* prave vybrane slovo */
    word *next = NULL;  /* nasledovnik slova ve zretezenem seznamu */

    if(!hashtable) {    /* pointer na tabulku ukazuje na NULL */
        return;
    }

    for(i = 0; i < HASHTABLE_SIZE; i++) {
        item = hashtable[i];
        while(item) {   /* dokud item ukazuje na slovo (neni NULL) */
            next = item->next;

            if(item->string) {
                free(item->string);
            }

            free(item);

            item = next;

        }
    }
}

/*
 * ------------------------------------------------------------------------------------
 * Vypise obsah hash tabulky do konzole.
 * ------------------------------------------------------------------------------------
 */
void print_hashtable(word *hashtable[]) {
    int i;
    word *item = NULL;  /* prave vypisovane slovo */

    if(!hashtable) {
        return;
    }

    for(i = 0; i < HASHTABLE_SIZE; i++) {
        printf("index %d: ", i);

        item = hashtable[i];
        while(item) {   /* dokud item ukazuje na slovo (neni NULL) */
            printf("%s(%d spam %lf %d ham %lf) ",
                   item->string, item->spam_count, item->spam_probability, item->ham_count, item->ham_probability);

            item = item->next;
        }

        printf("\n");
    }
}


