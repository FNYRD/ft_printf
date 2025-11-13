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
    // size_t  prints;

	ft_printf("|%+08d|\n", 33);
    // ft_printf("caracteres impresos: %d\n", prints);
	return (0);
}

// aparentemente ya esta listo todo para formato numerico
// solo falta tratar los casos de string y char con precision y -