/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:40:37 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/09 18:13:18 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	get_bit(unsigned char num, int k)
{
	return (num & (1 << k));
}

void	send_uchar(unsigned char c, pid_t pid)
{
	size_t	i;

	i = 0;
	while (i < sizeof(unsigned char) * 8)
	{
		if (get_bit(c, i) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

void	send_str(unsigned char *str, pid_t pid)
{
	int	i;

	i = 0;
	ft_printf("%s\n", str);
	while (i < (int)strlen((char *)str))
	{
		send_uchar(str[i], pid);
		i++;
	}
}
