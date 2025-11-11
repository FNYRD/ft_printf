/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:20:12 by jericard          #+#    #+#             */
/*   Updated: 2025/11/11 13:20:14 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	padding(const char *data, int precision, size_t width, int flag)
{
	if (data == 0 && precision == 0)
	{
		data = "";
		return (0);
	}
	if (flag == 0)
		return (ft_putminzero(data, width, flag));
	else if (flag == 1)
		return (ft_putminzero(data, width, flag));
	else if (flag == 2)
		return (ft_dotcase(data, width, precision, 1));
	else if (flag == 3)
		return (ft_dotcase(data, width, precision, 0));
	else
		return (ft_putstr(data));
}

size_t	ft_manager(const char *data, int precision, int width, int flag, int signalflag, char type)
{
	long long	width2;

	width2 = width;
	if (width2 < 0 )
	{
		width2 = -width2;
		if (flag < 1)
			flag = 1;
		else if (flag == 3)
			flag = 2;
	}
	if (type == 'd' || type == 'u' || type == 'i')
		return (padding(data, precision, width2, flag));
}
// recibir las flags y luego distribuirlas 
