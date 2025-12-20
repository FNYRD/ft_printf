/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:37:41 by jericard          #+#    #+#             */
/*   Updated: 2025/12/19 14:37:42 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*helper(va_list *arg)
{
	char	*ptr;

	ptr = va_arg(*arg, char *);
	if (ptr == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(ptr));
}

static char	*charter(const char c, va_list *arg)
{
	if (c == '%')
	{
		(void)arg;
		return (ft_ctos('%'));
	}
	return (ft_ctos(((char)va_arg(*arg, int))));
}

static char	*hexapoint(char *data)
{
	char	*temp;

	if (!data)
		return (NULL);
	temp = ft_strjoin("0x", data);
	if (!temp)
	{
		free(data);
		return (NULL);
	}
	free(data);
	return (temp);
}

char	*ft_stringer(const char c, va_list *arg)
{
	void	*p;

	if (c == 's')
		return (helper(arg));
	if (c == 'x' || c == 'X')
		return (ft_hexa(va_arg(*arg, unsigned int), c));
	else if (c == 'u')
		return (ft_utoa(va_arg(*arg, unsigned int)));
	else if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(*arg, int)));
	else if (c == 'c' || c == '%')
		return (charter(c, arg));
	else if (c == 'p')
	{
		p = va_arg(*arg, void *);
		if (!p)
			return (ft_strdup("(nil)"));
		return (hexapoint(ft_hexa((unsigned long long)p, 'x')));
	}
	return (NULL);
}
