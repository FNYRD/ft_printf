#include "ft_printf.h"

void	ft_putstr(char *s)
{
	unsigned long	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}