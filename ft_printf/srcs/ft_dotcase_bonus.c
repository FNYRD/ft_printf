#include "ft_printf.h"

// if precision < positions we'll use the difference between positions - precision
// else, we'll use precision as positions
// in cases with just the flag '.' (without '-')we'll use ft_putminzero with the 0 flag
// in case fo flag == 1 it means that there's a '-' (left indentation) present
void	ft_dotcase(char *str, unsigned long long positions, unsigned long long precision, unsigned long long flag)
{
	if (precision < positions)
	{
		positions -= precision;
		if (flag)
		{
			ft_putminzero(str, precision, 0);
			while (positions-- > 0)
				ft_putchar(' ');
		}
		else
		{
			while (positions-- > 0)
				ft_putchar(' ');
			ft_putminzero(str, precision, 0);
		}
	}
	else
	{
		if (str[0] == '-')
			precision++;
		ft_putminzero(str, precision, 0);
	}
}