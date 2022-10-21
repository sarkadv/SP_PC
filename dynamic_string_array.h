#ifndef SP_PC_DYNAMIC_STRING_ARRAY_H
#define SP_PC_DYNAMIC_STRING_ARRAY_H

#define INIT_ARRAY_SIZE 200     // zacneme na pomerne kratke delce souboru, abychom neplytvali pameti
#define MAX_STRING_LENGTH 30   // nad 30 znaku maji jen ta nejdelsi anglicka slova

typedef struct {
    char (*array)[MAX_STRING_LENGTH];       // pole ukazatelu na char = pole stringu
    int size;
    int used;
} dynamic_string_array;

void init_array(dynamic_string_array *a);
void add_to_array(dynamic_string_array *a, char *string);
void print_array(dynamic_string_array *a);

#endif
