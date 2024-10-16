#include "tests.h"


void test_reader_only_text(void)
{
    char    *FILENAME = "test_reader_only_text_1.txt";
    char    *TEXT = "Eu sou um texto e estou testando o reader da print";
    int     fd = open_text_file(FILENAME);
    char    *expect = ft_calloc(52, sizeof(char));

    sprintf(expect, "%s", TEXT);
    ft_reader(TEXT, fd);
    close(fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);

    FILENAME = "test_reader_only_text_2.txt";
    TEXT = "123456789";
    fd = open_text_file(FILENAME);
    expect = ft_calloc(52, sizeof(char));

    sprintf(expect, "%s", TEXT);
    ft_reader(TEXT, fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);

    FILENAME = "test_reader_only_text_3.txt";
    TEXT = "!@#$¨&*()-+=";
    fd = open_text_file(FILENAME);
    expect = ft_calloc(52, sizeof(char));

    sprintf(expect, "%s", TEXT);
    ft_reader(TEXT, fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);

    FILENAME = "test_reader_only_text_4.txt";
    TEXT = " \t\n\e\32";
    fd = open_text_file(FILENAME);
    expect = ft_calloc(52, sizeof(char));

    sprintf(expect, "%s", TEXT);
    ft_reader(TEXT, fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);
}

void test_reader_digit_correct(void)
{
    char    *FILENAME = "test_reader_digit_1.txt";
    char    *TEXT = "valor: %d";
    int     DIGIT = -100;
    int     fd = open_text_file(FILENAME);
    char    *expect = ft_calloc(10, sizeof(char));

    sprintf(expect, TEXT, DIGIT);
    ft_reader(TEXT, fd, DIGIT);
    close(fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);

    FILENAME = "test_reader_digit_2.txt";
    TEXT = "valor: %d";
    DIGIT = 100;
    fd = open_text_file(FILENAME);
    expect = ft_calloc(10, sizeof(char));

    sprintf(expect, TEXT, DIGIT);
    ft_reader(TEXT, fd, DIGIT);
    close(fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);
}

void test_reader_digit_incorrect(void)
{
    char    *FILENAME = "test_reader_digit_3.txt";
    char    *TEXT = "valor: %d";
    char    DIGIT = 'a';
    int     fd = open_text_file(FILENAME);
    char    *expect = ft_calloc(10, sizeof(char));

    sprintf(expect, TEXT, DIGIT);
    ft_reader(TEXT, fd, DIGIT);
    close(fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);
}

void test_reader_string_correct(void)
{
    char    *FILENAME = "test_reader_string_1.txt";
    char    *TEXT = "valor: %s";
    char    *STR = "test";
    int     fd = open_text_file(FILENAME);
    char    *expect = ft_calloc(10, sizeof(char));

    sprintf(expect, TEXT, STR);
    ft_reader(TEXT, fd, STR);
    close(fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);

    FILENAME = "test_reader_string_2.txt";
    TEXT = "valor: %s";
    STR = "";
    fd = open_text_file(FILENAME);
    expect = ft_calloc(10, sizeof(char));

    sprintf(expect, TEXT, STR);
    ft_reader(TEXT, fd, STR);
    close(fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);
}

void test_reader_string_incorrect(void)
{
    char    *FILENAME = "test_reader_string_3.txt";
    char    *TEXT = "valor: %s";
    char    *STR = NULL;
    int     fd = open_text_file(FILENAME);
    char    *expect = ft_calloc(10, sizeof(char));

    sprintf(expect, TEXT, STR);
    ft_reader(TEXT, fd, STR);
    close(fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);
}

void test_reader_hexadecimal_correct(void)
{
    char    *FILENAME = "test_reader_hexadecimal_1.txt";
    char    *TEXT = "valor: %x";
    char    *STR = "test";
    int     fd = open_text_file(FILENAME);
    char    *expect = ft_calloc(10, sizeof(char));

    sprintf(expect, TEXT, (char *)STR);
    ft_reader(TEXT, fd, (char *)STR);
    close(fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);

    FILENAME = "test_reader_hexadecimal_2.txt";
    TEXT = "valor: %X";
    STR = "100";
    fd = open_text_file(FILENAME);
    expect = ft_calloc(10, sizeof(char));

    sprintf(expect, TEXT, STR);
    ft_reader(TEXT, fd, STR);
    close(fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);
}

void test_reader_hexadecimal_incorrect(void)
{
    char    *FILENAME = "test_reader_hexadecimal_3.txt";
    char    *TEXT = "valor: %x";
    char    *STR = NULL;
    int     fd = open_text_file(FILENAME);
    char    *expect = ft_calloc(10, sizeof(char));

    sprintf(expect, TEXT, STR);
    ft_reader(TEXT, fd, STR);
    close(fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);
}

void test_reader_pointer_correct(void)
{
    char    *FILENAME = "test_reader_pointer_1.txt";
    char    *TEXT = "valor: %p";
    char    *STR = "test";
    int     fd = open_text_file(FILENAME);
    char    *expect = ft_calloc(10, sizeof(char));

    sprintf(expect, TEXT, (char *)STR);
    ft_reader(TEXT, fd, (char *)STR);
    close(fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);
}

void test_reader_pointer_incorrect(void)
{
    char    *FILENAME = "test_reader_pointer_2.txt";
    char    *TEXT = "valor: %p";
    char    *STR = NULL;
    int     fd = open_text_file(FILENAME);
    char    *expect = ft_calloc(10, sizeof(char));

    sprintf(expect, TEXT, STR);
    ft_reader(TEXT, fd, STR);
    close(fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);
}

void test_reader_unsigned_correct(void)
{
    char    *FILENAME = "test_reader_unsigned_1.txt";
    char    *TEXT = "valor: %u";
    int     DIGIT = 100;
    int     fd = open_text_file(FILENAME);
    char    *expect = ft_calloc(10, sizeof(char));

    sprintf(expect, TEXT, DIGIT);
    ft_reader(TEXT, fd, DIGIT);
    close(fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);
}

void test_reader_unsigned_incorrect(void)
{
    char    *FILENAME = "test_reader_unsigned_2.txt";
    char    *TEXT = "valor: %u";
    int     DIGIT = -1;
    int     fd = open_text_file(FILENAME);
    char    *expect = ft_calloc(10, sizeof(char));

    sprintf(expect, TEXT, DIGIT);
    ft_reader(TEXT, fd, DIGIT);
    close(fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);
}

void test_reader_percent_correct(void)
{
    char    *FILENAME = "test_reader_percent_1.txt";
    char    *TEXT = "valor: %%%s";
    int     fd = open_text_file(FILENAME);
    char    *expect = ft_calloc(10, sizeof(char));

    sprintf(expect, TEXT, "");
    ft_reader(TEXT, fd, "");
    close(fd);
    TEST_ASSERT_EQUAL_STRING(read_text_file(FILENAME), expect);
}