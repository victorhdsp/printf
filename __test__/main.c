#include <stdio.h>
#include "tests.h"

int open_text_file(const char *path)
{
    return(creat(ft_strjoin("./output/", path), O_CREAT | O_WRONLY | S_IRWXU));
}

char *read_text_file(const char *path)
{
    char *buffer = malloc(52 * sizeof(char));
    int fd = open(ft_strjoin("./output/", path), O_RDONLY);
    if (fd != -1)
        read(fd, buffer, 52);
    else
        printf("\n Erro de diretório");
    close(fd);
    return (buffer);
}

void setUp(void) { }

void tearDown(void) { }

int main(void)
{
    UNITY_BEGIN();

    printf("\n========================\n");
    RUN_TEST(test_reader_only_text);
    RUN_TEST(test_reader_digit_correct);
    RUN_TEST(test_reader_digit_incorrect);
    RUN_TEST(test_reader_string_correct);
    RUN_TEST(test_reader_string_incorrect);
    RUN_TEST(test_reader_hexadecimal_correct);
    RUN_TEST(test_reader_hexadecimal_incorrect);
    RUN_TEST(test_reader_pointer_correct);
    RUN_TEST(test_reader_pointer_incorrect);
    RUN_TEST(test_reader_unsigned_correct);
    RUN_TEST(test_reader_unsigned_incorrect);
    RUN_TEST(test_reader_percent_correct);

    return UNITY_END();
}
