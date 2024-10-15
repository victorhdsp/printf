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
void *read_text_file(int fd);

void test_reader_only_text(void);

#endif