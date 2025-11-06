#include "ft_printf.h"

int ft_count_0xchar(unsigned long long n)
{
	if (n > 0)
	{
		n = n / 16;
        //call itself with recursion to create a
        //stack and add 1 every return, resulting in the corerct number of chars to
		// print by ft_hexa
		return (1 + (ft_count_0xchar(n)));
	}
	return (0);
}