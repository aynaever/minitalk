/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:40:37 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/06 12:54:13 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

int	getBit(int num, int k)
{
	return (num & (1 << k));
}

int	sendUchar(unsigned char c, pid_t pid)
{
	int	i;

	i = 0;
	while (i < sizeof(unsigned char))
	{
		if (getBit(c, i) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
	}
}

int	sendNum(int	num, pid_t pid)
{
	int	i;

	i = 0;
	while (i < sizeof(int))
	{
		if (getBit(num, i) == 0)
			kill (pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
	}
}
