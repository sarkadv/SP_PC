#ifndef SP_PC_WORD_HASHTABLE_H
#define SP_PC_WORD_HASHTABLE_H

#define HASHTABLE_SIZE 1511  /* velikost tabulky - prvocislo */
#define MAX_STRING_LENGTH 80   /* maximalni delka slova */

/*
 * ------------------------------------------------------------------------------------
 * Struktura pro slovo v hash tabulce.
 * ------------------------------------------------------------------------------------
 */
typedef struct item {
    char *string;   /* klic */
    int count;          /* kolikrat se slovo vyskytlo ve spamovych / hamovych souborech (podle zrovna nacitaneho souboru) */
    int spam_count;      /* kolikrat se slovo vyskytlo ve spamovych souborech */
    int ham_count;      /* kolikrat se slovo vyskytlo v hamovych souborech */
    double spam_probability;    /* pravdepodobnost, ze se slovo vyskytne v textu, jestlize je text spam */
    double ham_probability;     /* ravdepodobnost, ze se slovo vyskytne v textu, jestlize je text ham */
    struct item *next;  /* ukazatel na dalsi slovo ve zretezenem seznamu */
} word;

/*
 * ------------------------------------------------------------------------------------
 * Vlozi nove slovo do hash tabulky.
 * Vrati se struktura word reprezentujici dany textovy retezec (slovo).
 * Pokud se slovo nepodarilo vlozit, vrati se NULL.
 * ------------------------------------------------------------------------------------
 */
word* insert_string_to_hashtable(word *hashtable[], char *string);

/*
 * ------------------------------------------------------------------------------------
 * Pokusi se najit v hash tabulce slovo podle jeho klice (textovy retezec slova).
 * Vrati bud nalezene slovo (struktura word) nebo NULL (slovo nebylo nalezeno).
 * ------------------------------------------------------------------------------------
 */
word* find_by_key(word *hashtable[], char *key);

/*
 * ------------------------------------------------------------------------------------
 * Vypise obsah hash tabulky do konzole.
 * ------------------------------------------------------------------------------------
 */
void print_hashtable(word *hashtable[]);

/*
 * ------------------------------------------------------------------------------------
 * Nainicializuje hash tabulku na jeji danou velikost HASHTABLE_SIZE, danou konstantou.
 * Na vsech indexech v tabulce se bude nachazet hodnota NULL.
 * V pripade uspechu vraci 1, jinak 0.
 * ------------------------------------------------------------------------------------
 */
int init_hashtable(word *hashtable[]);

/*
 * ------------------------------------------------------------------------------------
 * Uvolni pamet alokovanou pro hash tabulku.
 * ------------------------------------------------------------------------------------
 */
void free_hashtable(word *hashtable[]);

#endif
