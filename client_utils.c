/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:40:37 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/10 13:48:17 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	get_bit(unsigned char num, int k)
{
	return (num & (1 << k));
}

int	ft_start(const char *s)
{
	int	i;

	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\r'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == ' ')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	len;
	int	i;
	int	sign;
	int	rslt;

	len = ft_strlen(nptr);
	i = ft_start(nptr);
	rslt = 0;
	sign = 1;
	if (nptr[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (nptr[i] == '+')
		i++;
	while (i < len)
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			rslt = nptr[i] + rslt * 10 - 48;
		else
			break ;
		i++;
	}
	return (sign * rslt);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
