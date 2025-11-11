#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

int probe(char *fmt, ...)
{
    va_list ap;
    int     width;

    va_start(ap, fmt);
    width = ft_width(fmt, &ap);
    va_end(ap);
    return width;
}

int main(void)
{
	ft_printf("numero %010.0i \n y otro: %u", -4000, 100);
	return (0);
}

// Notas para la funcion principal:

// con %s NULL se pasa en hardcode (null)

// %% y %X necesitaran hardcode para %x y %p con precision 0 (0X o 0x) y con % para usar el literal e imprimirlo
// con las flags width, - y 0

// la precision con %s si es menor que su len se recorta, sino se imprime tal cual

// la precision con digitos, si es mayor que su len rellena con 0 sino se imprimi tal cual esta