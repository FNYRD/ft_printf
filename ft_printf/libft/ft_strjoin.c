/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:06:06 by jericard          #+#    #+#             */
/*   Updated: 2025/10/21 15:06:08 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*helper_null(void)
{
	char	*p;

	p = malloc(1);
	if (!p)
		return (NULL);
	p[0] = '\0';
	return (p);
}

static char	*helper_lesscode(char const *s1, char const *s2)
{
	char	*new;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = malloc((len_s1 + len_s2) * sizeof(char) + 1);
	if (!new)
		return (NULL);
	new = ft_memcpy(new, s1, len_s1);
	i = 0;
	while (s2[i])
	{
		new[len_s1] = s2[i];
		i++;
		len_s1++;
	}
	new[len_s1] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (helper_null());
	if (!s1)
		s1 = "";
	else if (!s2)
		s2 = "";
	return (helper_lesscode(s1, s2));
}
