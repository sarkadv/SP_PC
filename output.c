#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "output.h"

/*
 * ------------------------------------------------------------------------------------
 * Ulozi do vystupniho souboru vysledky ve formatu:
 * <nazev testovaciho souboru>1.txt -> H/S
 * <nazev testovaciho souboru>2.txt -> H/S
 * <nazev testovaciho souboru>3.txt -> H/S
 * ...
 * Znak 'H' odpovida Hamu, znak 'S' Spamu.
 * Soubor, ktery ma prirazeny znak '0', se nepodarilo klasfikovat a bude zapsan jako
 * <nazev testovaciho souboru>3.txt -> x.
 * V pripade uspechu vraci 1, jinak 0.
 * ------------------------------------------------------------------------------------
 */
int print_results_to_file(char results[], int test_file_count, char *test_file_name_pattern, char *output_file_name) {
    FILE *f_p = NULL;   /* pointer na vystupni soubor */
    int i;

    if(!results || test_file_count <= 0 || !test_file_name_pattern || !output_file_name) {
        /* pointery na NULL nebo nesmyslne ciselne hodnoty */
        return 0;
    }

    errno = 0;      /* vynulovani globalni promenne errno */
    f_p = fopen(output_file_name, "w");

    if(!f_p) {      /* soubor se nepodarilo vytvorit */
        printf("Error while creating file %s: %s\n", output_file_name, strerror(errno));
        return 0;
    }
    else {
       for(i = 0; i < test_file_count; i++) {
           if(results[i] != '0') {      /* soubor se podarilo klasifikovat */
               fprintf(f_p, "%s%d.txt\t%c\n", test_file_name_pattern, (i + 1), results[i]);
           }
           else {
               fprintf(f_p, "%s%d.txt\t%c\n", test_file_name_pattern, (i + 1), 'x');
           }

           if(ferror(f_p)) {   /* pri I/O operaci s proudem stream doslo k chybe */
               printf("Error while writing to file %s: %d\n", output_file_name, ferror(f_p));
               clearerr(f_p);  /* vynulovani chyby ve stavove strukture FILE */
               return 0;
           }
       }
    }

    /* uzavreni souboru */
    errno = 0;
    fclose(f_p);
    if(errno) {     /* globalni promenna errno neni nulova - doslo k chybe */
        printf("Error while closing file %s: %s\n", output_file_name, strerror(errno));
        return 0;
    }

    return 1;
}
