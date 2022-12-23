#ifndef SP_PC_OUTPUT_H
#define SP_PC_OUTPUT_H

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
int print_results_to_file(char results[], int test_file_count, char *test_file_name_pattern, char *output_file_name);

#endif
