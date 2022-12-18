#ifndef SP_PC_TESTFILE_LOADER_H
#define SP_PC_TESTFILE_LOADER_H
#include "dynamic_string_array.h"

/*
 * ------------------------------------------------------------------------------------
 * Nacte slova z testovaciho souboru a ulozi je do dynamickeho pole.
 * ------------------------------------------------------------------------------------
 */
void load_strings_to_array(dynamic_string_array *array, char *file_name);

#endif
