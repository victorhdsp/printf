# ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

#define HEX "0123456789abcdef"
#define DEC "0123456789"

typedef struct  s_flag_data
{
    size_t  width;
    int     has_precision;
    size_t  precision;
    int     align;
    char    set;
    char    *prefix;
}               t_flag_data;

int     ft_printf(const char *str, ...);
int     ft_putchar(char c);
int     ft_putstr(char *str);
char	*ft_convert_base(unsigned long long nb, const char *base);
t_flag_data	*ft_create_flag_data(void);
void	ft_get_flag_data(char *flag, t_flag_data *flag_data);
char	*ft_fill(t_flag_data *flag_data, char *str);
int     ft_command_c_n(char *flag, int c);
int     ft_command_s_n(char *flag, char *str);
int     ft_command_d_n(char *flag, long nb);
int ft_command_hex_n(t_flag_data *flag_data, unsigned long nb, int upper);
int     ft_command_x_n(char *flag, unsigned int nb);
int     ft_command_upperx_n(char *flag, unsigned int nb);
int     ft_command_p_n(char *flag, void *point);
char	*ft_substr(t_flag_data *flag_data, char *str);

#endif