#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "word_hashtable.h"

/*
 * ------------------------------------------------------------------------------------
 * Vrati hash pro dany retezec.
 * ------------------------------------------------------------------------------------
 */
int hash_code(char *string) {
    int length = strlen(string);    /* delka textoveho retezce */
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
 * ------------------------------------------------------------------------------------
 */
word* insert_string_to_hashtable(word *hashtable[], char *string) {
    word *item = NULL;  /* nalezene slovo v hash tabulce, je NULL pokud v tabulce dane slovo jeste neni */
    int hash_index;     /* vypocitany hash pro nove slovo */

    /* zjistime, zda slovo uz v hash tabulce je */
    item = find_by_key(hashtable, string);

    if(item) {    /* jestlize slovo uz v tabulce je (item neni NULL), nevlozi se znovu */
        item->count++;
    }
    else {      /* vytvori se nova struktura word, ktera se vlozi do hash tabulky */
        item = malloc(sizeof(word));
        strcpy(item->string, string);
        item->count = 1;

        hash_index = hash_code(string);

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
 * Vrati bud nalezene slovo (struktura word) nebo NULL.
 * ------------------------------------------------------------------------------------
 */
word* find_by_key(word *hashtable[], char *key) {
    int index = hash_code(key);     /* hash pro dany klic */
    word *item = hashtable[index];      /* slovo na indexu danem hash kodem */

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
 * Nainicializuje hash tabulku na jeji danou velikost.
 * ------------------------------------------------------------------------------------
 */
void init_hashtable(word *hashtable[]) {
    int i;

    for(i = 0; i < HASHTABLE_SIZE; i++) {
        hashtable[i] = NULL;
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


