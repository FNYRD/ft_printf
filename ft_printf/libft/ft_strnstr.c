/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:08:48 by jericard          #+#    #+#             */
/*   Updated: 2025/10/16 18:08:51 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	helper(const char *big, const char *little, size_t len, size_t k)
{
	size_t	j;

	j = 0;
	while (len > 0 && little[j] && big[k] == little[j])
	{
		len--;
		k++;
		j++;
	}
	if (!little[j])
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*p;

	p = (char *)big;
	if (!ft_strlen(little))
		return (&p[0]);
	i = 0;
	while (len > 0 && big[i])
	{
		if (big[i] == little[0])
		{
			if (helper(big, little, len, i))
				return (&p[i]);
		}
		len--;
		i++;
	}
	return (NULL);
}
