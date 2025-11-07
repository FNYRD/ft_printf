/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:05:19 by jericard          #+#    #+#             */
/*   Updated: 2025/11/06 19:05:21 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	verifyer(char c)
{
	if (!c)
		return (0);
	if (c == '#')
		return (1);
	else if (c == ' ')
		return (1);
	else if (c == '.')
		return (1);
	else if (c == '-')
		return (1);
	else if (c == '+')
		return (1);
	else if (c == '0')
		return (1);
	else if (c == '*')
		return (1);
	else if (c >= '1' && c <= '9')
		return (1);
	return (0);
}

static int	flagger_dash(int flag)
{
	if (flag < 1)
		flag++;
	else
		flag--;
	return (flag);
}

static int	flagger_dot(int flag)
{
	if (flag == 1)
		flag += 1;
	else
		flag += 3;
	return (flag);
}

int	ft_flag(char *str)
{
	int	i;
	int	flag;

	flag = -1;
	i = -1;
	while (verifyer(str[++i]))
	{
		if (str[i] == '0' && flag < 1)
			flag = 0;
		if (str[i] == '-')
			flag = flagger_dash(flag);
		if (str[i] == '.')
			flag = flagger_dot(flag);
	}
	return (flag);
}
