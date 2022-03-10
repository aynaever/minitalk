/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_utils_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:16:26 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/10 14:53:15 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	char	temp;

	temp = ' ';
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		temp = '-';
		write(1, &temp, 1);
		ft_putnbr((-n));
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n <= 9 && n >= 0)
	{
		temp = n + 48;
		write(1, &temp, 1);
	}
}

void	ft_putnbru(unsigned int n)
{
	char	temp;

	temp = ' ';
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n <= 9)
	{
		temp = n + 48;
		write(1, &temp, 1);
	}
}

void	ft_puthex(unsigned int n)
{
	if (n >= 16)
	{
		ft_puthex(n / 16);
		ft_puthex(n % 16);
	}
	else if (n <= 9)
	{
		ft_putchar_fd(n + 48, 1);
	}
	else if (n < 16)
	{
		ft_putchar_fd(n + 87, 1);
	}
}

void	ft_puthe_x(unsigned int n)
{
	if (n >= 16)
	{
		ft_puthe_x(n / 16);
		ft_puthe_x(n % 16);
	}
	else if (n <= 9)
	{
		ft_putchar_fd(n + 48, 1);
	}
	else if (n < 16)
	{
		ft_putchar_fd(n + 55, 1);
	}
}

int	ft_size_nbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
