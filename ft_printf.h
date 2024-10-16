# ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

#define U_HEX "0123456789ABCDEF"
#define L_HEX "0123456789abcdef"
#define DEC "0123456789"

int ft_printf(const char *str, ...);
int ft_command_p(void *point);
int ft_putchar(unsigned char c);
int ft_putstr(unsigned char *str);
int ft_strlen(const char *str);
int ft_convert_base(unsigned long long nb, const char *base);
int ft_command_c(char c);
int ft_command_s(char *str);
int ft_command_d(long nb);
int ft_command_u(unsigned int nb);
int ft_command_x(unsigned int nb);
int ft_command_X(unsigned int nb);

#endif