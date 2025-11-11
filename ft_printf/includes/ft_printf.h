#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h> 

void	ft_putstr(const char *s);
void	ft_putchar(const char c);
void    ft_manager(const char *data, int precision, int width, int flag, char type); // Modificar para retornar el numero de chars escritos
void	ft_hexa_void(unsigned long long n, const char x);

char	*ft_ctos(const char c);
char	*ft_utoa(unsigned int n);
char	ft_datatype(const char *ptr);
char	*ft_stringer(const char c, va_list *arg);
char	*ft_hexa(unsigned long long n, char x);

int		ft_flag(const char *str);
int     signalflag(const char *str);
int		ft_skipping(const char c);
int		ft_precision(const char *str);
int		ft_width(const char *str, va_list *arg);
int		ft_printf(const char *, ...);
int		ft_count_0xchar(unsigned long long n);

size_t	ft_putminzero(const char *str, size_t positions, size_t flag);
size_t	ft_dotcase(const char *str, size_t positions, size_t precision, size_t flag);

#endif