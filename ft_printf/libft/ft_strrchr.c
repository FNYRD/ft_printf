/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:54:07 by jericard          #+#    #+#             */
/*   Updated: 2025/10/14 18:54:08 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s1;

	s1 = NULL;
	while (*s)
	{
		if ((unsigned char)c == (unsigned char)*s)
			s1 = s;
		s++;
	}
	if (s1)
		return ((char *)s1);
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}
