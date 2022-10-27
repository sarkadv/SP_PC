#ifndef SP_PC_WORD_HASHTABLE_H
#define SP_PC_WORD_HASHTABLE_H

#define HASHTABLE_SIZE 1511  // velikost tabulky - prvocislo
#define MAX_STRING_LENGTH 80   // vsechna slova z testovacich souboru se vejdou

typedef struct item {
    char string[MAX_STRING_LENGTH];   // klic
    int count;          // v kolika spamovych / hamovych souborech se slovo vyskytlo (podle zrovna nacitaneho souboru)
    int spam_count;      // v kolika spamovych souborech se slovo vyskytlo
    int ham_count;      // v kolika hamovych souborech se slovo vyskytlo
    double spam_probability;    // pravdepodobnost, ze slovo je spam
    double ham_probability;     // pravdepodobnost, ze slovo je ham
    struct item *next;  // ukazatel na dalsi slovo ve zretezenem seznamu
} word;

word* insert_string_to_hashtable(word *hashtable[], char *string);
word* find_by_key(word *hashtable[], char *key);
void print_hashtable(word *hashtable[]);
void init_hashtable(word *hashtable[]);

#endif
