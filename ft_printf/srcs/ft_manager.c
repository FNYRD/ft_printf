/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:20:12 by jericard          #+#    #+#             */
/*   Updated: 2025/11/11 13:20:14 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	width_positive(long long *width, int *flag)
{
	if (*(width) < 0)
	{
		*(width) = -*(width);
		if (*(flag) < 1)
			*(flag) = 1;
		else if (*(flag) == 3)
			*(flag) = 2;
	}
}

static size_t	padding(const char *data, va_list *arg, const char *format)
{
	long long	width;
	int			flag;

	flag = ft_flag(format);
	width = ft_width(format, arg);
	width_positive(&width, &flag);
	if (!data)
		return (0);
	if ((ft_precision(format) == 0 && data[0] == '0') && width)
		data = "";
	else if (ft_precision(format) == 0 && data[0] == '0' && !width)
		return (0);
	if (flag == 0  || (flag < 0 && width))
		return (ft_putminzero(data, width, flag));
	else if (flag == 1)
		return (ft_putminzero(data, width, flag));
	else if (flag == 2)
		return (ft_dotcase(data, width, ft_precision(format), 1));
	else if (flag == 3)
		return (ft_dotcase(data, width, ft_precision(format), 0));
	else
		ft_putstr(data);
	return (ft_strlen(data));
}

static size_t	hexapoint(const char *data, const char *format, va_list *arg)
{
	char	*temp;
	size_t	printed;

	temp = NULL;
	if (ft_datatype(format) == 'p' || ft_signalflag(format) >= 10)
	{
		if (ft_datatype(format) == 'X')
			temp = ft_strjoin("0X", data);
		else
			temp = ft_strjoin("0x", data);
		printed = padding(temp, arg, format);
		free(temp);
		return (printed);
	}
	(void)temp;
	return (padding(data, arg, format));
}

static size_t	numbers(const char *data, const char *format, va_list *arg, char type)
{
	char	*temp;
	size_t	printed;

	temp = NULL;
	if ((type == 'd' || type == 'i') && data[0] != '-' )
	{
		if (ft_signalflag(format) == 1)
			temp = ft_strjoin(" ", data);
		else if (ft_signalflag(format) == 2)
			temp = ft_strjoin("+", data);
		if (temp)
		{
			printed = padding(temp, arg, format);
			free(temp);
			return (printed);	
		}
	}
	(void)temp;
	return (padding(data, arg, format));	
}

size_t	ft_manager(const char *data, const char *format, va_list *arg)
{
	char	type;

	type = ft_datatype(format);
	if (type == 'd' || type == 'u' || type == 'i')
		return (numbers(data, format, arg, type));
	else if (type == 'x' || type == 'X' || type == 'p')
		return (hexapoint(data, format, arg));
	else
		return (0);
}
// Crear las impresions para hexa y pointer

// No así. hexapoint siempre termina liberando la cadena que r
// ecibe (después de ft_strjoin hace free(temp)), así que si le pasas el literal "0x0" 
// terminarías haciendo un free sobre memoria estática y se rompería todo. Si quieres construir 
// 0x0 manualmente, crea una copia dinámica (por ejemplo con ft_strdup("0"), concatena tú el prefijo 
// y luego pásala a hexapoint; o mejor, deja que hexapoint reciba la cadena "0" y, antes de prefijar, 
// compruebe if (data[0] == '0' && data[1] == '\0') para saltarse ese ft_strjoin.




// antiguo manager
//	size_t	ft_manager(const char *data, int precision, int width, int flag, int signalflag, char type)

// antiguo padding
//	static size_t	padding(const char *data, int precision, size_t width, int flag)