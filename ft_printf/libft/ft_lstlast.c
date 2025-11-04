/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:55:34 by jericard          #+#    #+#             */
/*   Updated: 2025/10/24 16:55:35 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	len;

	if (!lst)
		return (NULL);
	len = ft_lstsize(lst);
	while (len-- > 1)
		lst = lst->next;
	return(lst);
}
