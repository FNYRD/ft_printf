#include "ft_printf.h"

static void	helper(char *str, unsigned long long positions, unsigned long long flag)
{
	if (flag == 1)
	{
		ft_putstr(str);
		while (positions-- > 0)
			ft_putchar(' ');
	}
	else if (flag == 0)
	{
		while (positions-- > 0)
			ft_putchar('0');
		ft_putstr(str);	
	}
	else
	{
		while (positions-- > 0)
			ft_putchar(' ');
		ft_putstr(str);
	}
}
// flag 1 will indicate that flag == -, flag 0 == 0
void	ft_putminzero(char *str, unsigned long long positions, unsigned long long flag)
{
	unsigned long long	len;
	char			*ptr;

	len = ft_strlen(str);
	if (positions <= len)
	{
		ft_putstr(str);
		return ;
	}
	if (str[0] == '-')
	{
		ptr = &str[1];
		// positions--;
		ft_putchar('-');
	}
	else
		ptr = str;
	helper(ptr, (positions -= len), flag);
}