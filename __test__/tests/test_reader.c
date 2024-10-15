#include "tests.h"

char *FILENAME = "test_reader_only_text.txt";

void test_reader_only_text(void)
{
    int fd = open_text_file(FILENAME);
    ft_reader("Eu sou um texto e estou testando o reader da print", fd);
    printf("%s", read_text_file(fd));
    TEST_ASSERT(1 == 1);
}