#include "ft_printf.h"

void	ft_hexa_void(unsigned int n, char x)
{
	unsigned int	res;
    unsigned int    capital;
    // depends of what kind of flag is used, it'll add the correct number to
    // get the correct output
    if (x == 88)
        capital = 7;
    else
        capital = 39;
	if (n == 0)
		return ;
	if (n > 0)
	{
		res = n % 16;
		n = n / 16;
        //call itself with recursion to create a
        //stack and print the result on reverse way
		ft_hexa_void(n, x);
		if (res >= 10)
			ft_putchar((res + '0') + capital);
		else
			ft_putchar(res + '0');
	}
}