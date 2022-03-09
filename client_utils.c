/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:40:37 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/09 01:37:03 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	getBit(int num, int k)
{
	return (num & (1 << k));
}

void	sendUchar(unsigned char c, pid_t pid)
{
	size_t	i;

	i = 0;
	while (i < sizeof(unsigned char) * 8)
	{
		if (getBit(c, i) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(1);
	}
}

void	sendNum(int	num, pid_t pid)
{
	int	i;

	i = 0;
	while (i < (int) (sizeof(int) * 8))
	{
		if (getBit(num, i) == 0)
			kill (pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(1);
	}
}

void	sendStr(unsigned char *str, pid_t pid)
{
	int	i;

	i = 0;
	ft_printf("%s\n", str);
	while (i < (int)strlen((char *)str))
	{
		sendNum(str[i], pid);
		i++;
	}
}
