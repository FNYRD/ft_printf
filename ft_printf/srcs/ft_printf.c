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

void	sender2manager(const char *format, va_list *arg)
{
	char	*data;

	data = ft_stringer(ft_datatype(format), arg);
	ft_manager(data, format, arg);
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
			sender2manager(&format[i], &arg);
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

// antiguo helper // Notas para la funcion principal:

// con %s NULL se pasa en hardcode (null)

// la precision con %s si es menor que su len se recorta, sino se imprime tal cual


// |%-18p| con (void *)0 se borra porque el “caso especial cero con precisión cero” siempre 
// se ejecuta: en padding (ft_printf/srcs/ft_manager.c (lines 35-41)) se comprueba 
// ft_precision(format) == 0 sin verificar si realmente había un .. Tu ft_precision devuelve 0 incluso 
// cuando no hay precisión, así que para %p normal se entra en el bloque y data se reemplaza por "". 
// Solución rápida: solo apliques ese borrado cuando el flag indique un formato con . (flag 2 o 3), o 
// haz que ft_precision devuelva -1 cuando no haya . y compara contra ese valor. Con ese cambio el 
// puntero nulo imprimirá 0x0 y seguirás cumpliendo la regla de “no imprimir nada” únicamente cuando la 
// precisión se indicó explícitamente como 0.

// aparentemente ya esta listo todo para formato numerico
// solo falta tratar los casos de string y char con precision y -

//		ft_manager(data, ft_precision(format), ft_width(format, arg), ft_flag(format), ft_datatype(format), signalflag(format));
