#include <stdio.h>
#include <string.h>
#include "output.h"

/*
 * ------------------------------------------------------------------------------------
 * Ulozi do vystupniho souboru vysledky ve formatu:
 * <nazev testovaciho souboru>1.txt -> H/S
 * <nazev testovaciho souboru>2.txt -> H/S
 * <nazev testovaciho souboru>3.txt -> H/S
 * ...
 * Znak 'H' odpovida Hamu, znak 'S' Spamu.
 * Soubor, ktery ma prirazeny znak '0', se nepodarilo klasfikovat a nebude vypsan.
 * ------------------------------------------------------------------------------------
 */
void print_results_to_file(char results[], int test_file_count, char *test_file_name_pattern, char *output_file_name) {
    FILE *f_p = NULL;   /* pointer na vystupni soubor */
    int i;

    f_p = fopen(output_file_name ,"w");

    if(!f_p) {  /* soubor se nepodarilo vytvorit */
        printf("cant create file");
    }
    else {
       for(i = 0; i < test_file_count; i++) {
           if(results[i] != '0') {      /* soubor se podarilo klasifikovat */
               fprintf(f_p, "%s%d.txt\t%c\n", test_file_name_pattern, (i + 1), results[i]);
           }
       }
    }

    /* uzavreni souboru */
    fclose(f_p);
}
