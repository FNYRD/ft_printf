/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringer_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:39:10 by jericard          #+#    #+#             */
/*   Updated: 2025/11/07 13:39:19 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*helper(va_list *arg)
{
	char	*ptr;

	ptr = va_arg(*arg, char *);
	if (ptr == NULL)
		return (ft_strdup("(null)"));
	else
		return (ft_strdup(ptr));
}

char	*ft_stringer(const char c, va_list *arg)
{
	if (c == 'x' || c == 'X')
		return (ft_hexa(va_arg(*arg, unsigned int), c));
	else if (c == 'u')
		return (ft_utoa(va_arg(*arg, unsigned int)));
	else if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(*arg, int)));
	else if (c == 'c' || c == '%')
	{
		if (c == '%')
			return (ft_ctos('%'));
		else
			return (ft_ctos(((char)va_arg(*arg, int))));
	}
	else if (c == 's')
		return (helper(arg));
	else if (c == 'p')
		return (ft_hexa(((unsigned long long)va_arg(*arg, void *)), 'x'));
	return (NULL);
}
