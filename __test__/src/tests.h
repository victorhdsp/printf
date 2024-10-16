#ifndef TESTS_H
#define TESTS_H

#include "unity.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "printf.h"
#include "libft.h"

int open_text_file(const char *path);
char *read_text_file(const char *path);

void test_reader_only_text(void);
void test_reader_digit_correct(void);
void test_reader_digit_incorrect(void);
void test_reader_string_correct(void);
void test_reader_string_incorrect(void);
void test_reader_hexadecimal_correct(void);
void test_reader_hexadecimal_incorrect(void);
void test_reader_pointer_correct(void);
void test_reader_pointer_incorrect(void);
void test_reader_unsigned_correct(void);
void test_reader_unsigned_incorrect(void);
void test_reader_percent_correct(void);

#endif