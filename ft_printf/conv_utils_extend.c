/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_utils_extend.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:06:12 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/10 14:51:55 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	d_conv(va_list ptr)
{
	int	len;
	int	n;

	len = 0;
	n = va_arg(ptr, int);
	ft_putnbr(n);
	len += ft_size_nbr(n);
	return (len);
}

int	i_conv(va_list ptr)
{	
	int	len;
	int	n;

	len = 0;
	n = va_arg(ptr, int);
	ft_putnbr(n);
	len += ft_size_nbr(n);
	return (len);
}

int	u_conv(va_list ptr)
{
	unsigned int	n;
	int				len;

	len = 0;
	n = va_arg(ptr, unsigned int);
	ft_putnbru(n);
	len += ft_size_nbru(n);
	return (len);
}

int	x_conv(va_list ptr)
{
	unsigned int	n;
	int				len;

	len = 0;
	n = va_arg(ptr, unsigned int);
	ft_puthex(n);
	len += ft_size_nbrx(n);
	return (len);
}

int	xx_conv(va_list ptr)
{
	unsigned int	n;
	int				len;

	len = 0;
	n = va_arg(ptr, unsigned int);
	ft_puthe_x(n);
	len += ft_size_nbrx(n);
	return (len);
}
