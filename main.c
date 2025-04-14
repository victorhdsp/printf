#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	void *point;
	int count;

	count = ft_printf(" %25.13x ", 1);
	printf(", count: %d;\n", count);
	count = printf(" %25.13x ", 1);
	printf(", count: %d;\n", count);
}