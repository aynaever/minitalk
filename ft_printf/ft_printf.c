/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:31:11 by anaouadi          #+#    #+#             */
/*   Updated: 2021/08/25 18:54:57 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			len;
	int			i;
	va_list		list;

	va_start(list, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			len += write(1, &str[i], 1);
		else
		{
			len += choose_conv(list, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(list);
	return (len);
}
