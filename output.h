#ifndef SP_PC_OUTPUT_H
#define SP_PC_OUTPUT_H

/*
 * ------------------------------------------------------------------------------------
 * Ulozi do vystupniho souboru vysledky ve formatu:
 * <nazev testovaciho souboru>1.txt -> H/S
 * <nazev testovaciho souboru>2.txt -> H/S
 * <nazev testovaciho souboru>3.txt -> H/S
 * ...
 * Pismeno H odpovida Hamu, pismeno S Spamu.
 * ------------------------------------------------------------------------------------
 */
void print_results_to_file(char results[], int test_file_count, char *test_file_name_pattern, char *output_file_name);

#endif
