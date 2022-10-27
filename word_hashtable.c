#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "word_hashtable.h"

int hash_code(char *string) {
    int length = strlen(string);
    int code = 0;
    int i;

    for(i = length - 1; i >= 0; i--) {
        code += ((int)(string[i] * pow(31, (i + 1))) % HASHTABLE_SIZE);
    }

    code = code % HASHTABLE_SIZE;
    return code;
}

word* insert_string_to_hashtable(word *hashtable[], char *string) {    // vlozi novy retezec do hash tabulky
    word *item = find_by_key(hashtable, string);
    if(item) {    // jestlize slovo uz v tabulce je, nevlozi se znovu
        item->count++;
    }
    else {
        item = malloc(sizeof(word));
        strcpy(item->string, string);
        item->count = 1;

        int hash_index = hash_code(string);

        if(hashtable[hash_index]) { // na indexu neni NULL - uz je tam nejake slovo
            item->next = hashtable[hash_index];

        }
        hashtable[hash_index] = item;
    }

    return item;

}

word* find_by_key(word *hashtable[], char *key) {
    int index = hash_code(key);
    word *item = hashtable[index];

    while(item) {   // v pointeru je slovo
        if(!strcmp(item->string, key)) {    // strcmp() vrati 0, jestlize se retezce rovnaji
            return item;
        }
        item = item->next;
    }

    return NULL;
}

void init_hashtable(word *hashtable[]) {
    int i;

    for(i = 0; i < HASHTABLE_SIZE; i++) {
        hashtable[i] = NULL;
    }
}

void print_hashtable(word *hashtable[]) {
    int i;
    for(i = 0; i < HASHTABLE_SIZE; i++) {
        printf("index %d: ", i);

        word *item = hashtable[i];
        while(item) {   // dokud item neni null
            printf("%s(%d spam %lf %d ham %lf) ", item->string, item->spam_count, item->spam_probability, item->ham_count, item->ham_probability);

            item = item->next;
        }

        printf("\n");
    }
}


