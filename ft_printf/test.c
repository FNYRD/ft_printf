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
    void *ptr = (void *)0x12345;

    ft_printf("|%-#20p|", ptr);
    // printf    ("|%-#20p|", ptr);

    ft_printf("|%020p|", ptr);
    // printf    ("|%020p|", ptr);


    return (0);



}

// erroes

// ft_printf("|%10.3u|", 4294967295);|     4294967295|% 

// NULL => (null)
// !P => (nil)