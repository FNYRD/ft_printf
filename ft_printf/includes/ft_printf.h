#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> 

void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_hexa_void(unsigned int n, char x);
void	ft_putminzero(char *str, unsigned long positions, unsigned int flag);
void	ft_dotcase(char *str, unsigned long positions, unsigned long precision, int flag);

char	*ft_hexa(unsigned int n, char x);

int     ft_count_0xchar(unsigned int n);


#endif