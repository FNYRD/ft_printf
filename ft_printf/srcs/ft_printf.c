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
#include <stdio.h> //BORRAR!

void	helper(const char *format, va_list *arg)
{
	char	*data;

	data = ft_stringer(ft_datatype(format), arg);
	ft_manager(data, ft_precision(format), ft_width(format, arg), ft_flag(format), ft_datatype(format), signalflag(format));
	free(data);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;

	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			helper(&format[i], &arg);
			while (ft_skipping(format[i]))
				i++;
			if (format[i])
				i++;
			continue ;
		}
		ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (0);
}
// la linea es demasido larga por lo que voy a tener que hacer una linea mas corta pasando solo format y arg,
// recibiendo en la otra funcion de manager y separandolo todo en variables, dentro de la separacion de variables 
// comenzar a usarla con la funcion que ya esxiste