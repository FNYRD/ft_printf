#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h> 

void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_hexa_void(unsigned long long n, char x);
void	ft_putminzero(char *str, unsigned long long positions, unsigned long long flag);
void	ft_dotcase(char *str, unsigned long long positions, unsigned long long precision, unsigned long long flag);

char	*ft_hexa(unsigned long long n, char x);

int     ft_printf(const char *, ...);
int     ft_count_0xchar(unsigned long long n);

#endif