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

void	ft_dotcase(const char *str,
			unsigned long long positions,
			unsigned long long precision, unsigned long long flag)
{
	if (str[0] == '-')
		precision++;
	if (precision < positions)
	{
		positions -= precision;
		if (flag)
		{
			ft_putminzero(str, precision, 0);
			while (positions-- > 0)
				ft_putchar(' ');
		}
		else
		{
			while (positions-- > 0)
				ft_putchar(' ');
			ft_putminzero(str, precision, 0);
		}
	}
	else
	{
		ft_putminzero(str, precision, 0);
	}
}
