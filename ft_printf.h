# ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

#define HEX "0123456789abcdef"
#define DEC "0123456789"

int     ft_printf(const char *str, ...);
int     ft_putchar(char c);
int     ft_putstr(char *str);
int	    ft_numlen(unsigned long long n);
char    *ft_convert_base(unsigned long long nb, const char *base);
char    *ft_command_p(char *flag, unsigned long point);
char    *ft_command_c(char *flag, int c);
char    *ft_command_s(char *flag, char *str);
char    *ft_command_d(char *flag, long nb);
char    *ft_command_x(char *flag, unsigned int nb, int upper);
int     ft_traitment_null(char c, char *str);
char    *ft_width(char *flag, char *str);
char	*ft_precision_string(char *flag, char *str);
char	*ft_precision_digit(char *flag, char *str);
char	*ft_prefix(char *flag, char *str);

#endif