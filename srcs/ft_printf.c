/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:07:03 by jericard          #+#    #+#             */
/*   Updated: 2025/11/06 13:07:04 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	sender2manager(va_list *arg, char type)
{
	char	*data;
	size_t	printed;

	printed = 0;
	data = ft_stringer(type, arg);
	if (!data)
		return (-1);
	printed = ft_putstr(data);
	free(data);
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	size_t	printed;

	i = 0;
	printed = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			printed += sender2manager(&arg, format[i + 1]);
			i += 2;
			continue ;
		}
		printed += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (printed);
}
