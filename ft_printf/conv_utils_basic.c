/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_utils_basic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 06:28:40 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/10 14:53:51 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	choose_conv(va_list ptr, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += c_conv(ptr);
	else if (c == 's')
		len += s_conv(ptr);
	else if (c == 'p')
		len += p_conv(ptr);
	else if (c == 'd')
		len += d_conv(ptr);
	else if (c == 'i')
		len += i_conv(ptr);
	else if (c == 'u')
		len += u_conv(ptr);
	else if (c == 'x')
		len += x_conv(ptr);
	else if (c == 'X')
		len += xx_conv(ptr);
	else if (c == '%')
		len += write(1, "%", 1);
	return (len);
}

int	c_conv(va_list ptr)
{
	int		len;
	char	c;

	len = 1;
	c = (char) va_arg(ptr, int);
	write(1, &c, 1);
	return (len);
}

int	s_conv(va_list ptr)
{
	int		i;
	char	*str;

	str = va_arg(ptr, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	p_conv(va_list ptr)
{
	unsigned long long int	n;
	int						len;

	len = 0;
	n = va_arg(ptr, unsigned long long int);
	if (n == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	len += 2;
	ft_putptr(n);
	len += ft_size_nbrp(n);
	return (len);
}

void	ft_putptr(unsigned long long int n)
{
	if (n < 0)
		return ;
	if (n >= 16)
	{
		ft_putptr(n / 16);
		ft_putptr(n % 16);
	}
	else if (n <= 9 && n >= 0)
	{
		ft_putchar_fd(n + 48, 1);
	}
	else if (n < 16)
	{
		ft_putchar_fd(n + 87, 1);
	}
}
