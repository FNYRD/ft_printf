#include "ft_printf.h"

// flag 1 will indicate that flag == -, flag 0 == 0
void	ft_putminzero(char *str, unsigned long positions, unsigned int flag)
{
	unsigned long len;

	len = ft_strlen(str);
	positions -= len;
	if (flag == 1)
	{
		ft_putstr(str);
		while (positions-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (positions-- > 0)
			ft_putchar('0');
		ft_putstr(str);	
	}
}