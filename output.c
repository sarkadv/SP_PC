#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "output.h"

print_results_to_file(char results[], int test_file_count, char *test_file_name_pattern, char *output_file_name) {
    FILE *f_p = NULL;
    int i;

    f_p = fopen(output_file_name ,"w");

    if(!f_p) {
        printf("cant create file");
    }
    else {
       for(i = 0; i < test_file_count; i++) {
           fprintf(f_p, "%s%d.txt\t%c\n", test_file_name_pattern, (i + 1), results[i]);
       }
    }

    fclose(f_p);
}
