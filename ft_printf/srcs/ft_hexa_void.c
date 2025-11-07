/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_void.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:06:25 by jericard          #+#    #+#             */
/*   Updated: 2025/11/06 13:06:26 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_void(unsigned long long n, char x)
{
	unsigned long long	res;
	unsigned long long	capital;

	if (x == 88)
		capital = 7;
	else
		capital = 39;
	if (n == 0)
		return ;
	if (n > 0)
	{
		res = n % 16;
		n = n / 16;
		ft_hexa_void(n, x);
		if (res >= 10)
			ft_putchar((res + '0') + capital);
		else
			ft_putchar(res + '0');
	}
}
