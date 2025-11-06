#include "ft_printf.h"


static char *helper(void)
{
    char *p;

    p = malloc(2);
    if (!p)
        return NULL;
    p[0] = '0';
    p[1] = '\0';
    return p;
}

char	*ft_hexa(unsigned long long n, char x)
{
	unsigned int	res;
    unsigned int    capital;
	unsigned int	len;
	char			*p;

	if (n == 0)
		return helper();
	len = ft_count_0xchar(n);
	p = malloc(len * sizeof(char) + 1);
	if (!p)
		return (NULL);
    // depends of what kind of flag is used, it'll add the correct number to
    // get the correct output
    if (x == 88)
        capital = 7;
    else
        capital = 39;
	p[len--] = '\0';
	while (n > 0)
	{
		res = n % 16;
		n = n / 16;
        // fill out the array with the chars in reverse way, using it as a stack
		if (res >= 10)
			p[len--] = ((res + '0') + capital);
		else
			p[len--] = (res + '0');
	}
	return (p);
}
