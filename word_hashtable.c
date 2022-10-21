#include <stdlib.h>

#define HASHTABLE_SIZE 1511  // velikost tabulky - prvocislo
#define MAX_STRING_LENGTH 30   // nad 30 znaku maji jen ta nejdelsi anglicka slova
#define MAX_FILE_COUNT 380

typedef struct item{
    char string[MAX_STRING_LENGTH];   // klic
    int count[MAX_FILE_COUNT];      // hodnota - pole integeru, velikosti odpovida poctu trenovacich souboru, na kazdem indexu
                    // boolean, zda se slovo v souboru vyskytlo ci ne
    struct item *next;  // ukazatel na dalsi slovo ve zretezenem seznamu
} word;

void init_hashtable (word *hashtable) {
    hashtable = malloc(sizeof(word) * HASHTABLE_SIZE);
}

int hash_code(char *string) {
    int code = 0;
    int i;

    for(i = 0; i < MAX_STRING_LENGTH; i++){
        if(string[i] == '\0'){
            break;
        }

        code += (int)string[i];
    }

    code = code % HASHTABLE_SIZE;
    return code;
}

int string_equals(char *string1, char *string2) {
    int i = 0;

    while(string1[i] != '\0') {
        if(string1[i] != string2[i]) {
            return 0;
        }
        i++;
    }

    return 1;
}

word* find_by_key(word *hashtable, char *key) {
    int index = hash_code(key);

    do {
        if(string_equals(hashtable[index].string, key)) {
            return &hashtable[index];
        }
    } while (hashtable[index].next);    // dokud dalsi zretezeny prvek neni null

    return NULL;
}


