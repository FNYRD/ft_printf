#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

int main(void)
{
	char	*p;
	// ft_putminzero("42", 8, 1);
	// ft_dotcase("42", 8, 5, 1);
	// printf("%d", ft_count_0xchar(255));
	p = ft_hexa(42, 'x');
	printf("%s", p);
	return (0);
}
