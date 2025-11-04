/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:35:02 by jericard          #+#    #+#             */
/*   Updated: 2025/10/14 18:35:04 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)c == (unsigned char)*s)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == (unsigned char)*s)
		return ((char *)s);
	return (NULL);
}
