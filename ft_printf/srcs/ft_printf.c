#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	i;
	va_list	arg;

	va_start(arg, format);
	i = -1;
	while (format[++i])
		ft_putchar(format[i]);
	return (0);
}