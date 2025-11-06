#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"
#include "test.h"

int main(void)
{
	// char	*p;

	ft_printf("hola que tal");
    // printf("%d", ft_count_0xchar(255));
	// ft_dotcase("0x", 6, 6, 0);
	// p = ft_substr("(null)", 0, 3);
	// ft_putminzero("%", 5, 0);
	// printf("%s", p);
	// ft_putstr(p);
	// printf("Original: %p\n", p);
	// printf("0x");
	// ft_putminzero(ft_hexa((unsigned long long)p,'x'), 13, 0);
	return (0);
}

// Notas para la funcion principal:

// con %s NULL se pasa en hardcode (null)

// %% y %X necesitaran hardcode para %x y %p con precision 0 (0X o 0x) y con % para usar el literal e imprimirlo
// con las flags width, - y 0

// la precision con %s si es menor que su len se recorta, sino se imprime tal cual

// la precision con digitos, si es mayor que su len rellena con 0 sino se imprimi tal cual esta