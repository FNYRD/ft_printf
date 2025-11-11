/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dotcase_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:06:08 by jericard          #+#    #+#             */
/*   Updated: 2025/11/06 13:06:10 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	helper(const char *str, size_t positions, size_t precision, size_t flag)
{
	size_t	len;

	positions -= precision;
	len = positions;
	if (flag)
	{
		len += ft_putminzero(str, precision, 0);
		while (positions-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (positions-- > 0)
			ft_putchar(' ');
		len += ft_putminzero(str, precision, 0);
	}
	return (len);
}

size_t	ft_dotcase(const char *str, size_t positions, size_t precision, size_t flag)
{
	if (str[0] == '-')
		precision++;
	if (precision < positions)
	{
		return (helper(str, positions, precision, flag));
	}
	else
	{
		return (ft_putminzero(str, precision, 0));
	}
}
