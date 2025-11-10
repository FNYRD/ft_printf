/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datatype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:27:55 by jericard          #+#    #+#             */
/*   Updated: 2025/11/07 17:27:57 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_datatype(const char *ptr)
{
	int	i;
	
	i = 0;
	while (ft_skipping(ptr[i]))
		i++;
	return (ptr[i]);
}
