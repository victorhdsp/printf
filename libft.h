# ifndef LIBFT_H
#define LIBFT_H

# include <stdlib.h>
#include "ft_printf.h"

void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int     ft_atoi(const char *nptr);
int     ft_isdigit(int c);

#endif