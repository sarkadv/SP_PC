#ifndef SP_PC_EVAL_H
#define SP_PC_EVAL_H
#include "word_hashtable.h"

void classify_test_files(word *dictionary[], char results[], char *file_name_pattern, int file_count, double spam_file_probability, double ham_file_probability);

#endif
