#include <stdio.h>
#include "tests.h"

int open_text_file(const char *path)
{
    return(open(ft_strjoin("./output/", path), O_RDWR));
}

void *read_text_file(int fd)
{
    void *buffer = NULL;
    read(fd, buffer, -1);
    return(buffer);
}

void setUp(void) { }

void tearDown(void) { }

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_reader_only_text);
    
    return UNITY_END();
}
