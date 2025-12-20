/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_0xchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:43:25 by jericard          #+#    #+#             */
/*   Updated: 2025/12/19 14:43:27 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_0xchar(unsigned long long n)
{
	if (n > 0)
	{
		n = n / 16;
		return (1 + (ft_count_0xchar(n)));
	}
	return (0);
}
