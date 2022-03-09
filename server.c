/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:11:33 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/09 01:13:52 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_info;

void	handler(int	sig)
{
	if (sig == SIGUSR2)
		g_info.temp = setBitChar(g_info.temp, g_info.i);
	else if (sig == SIGUSR1)
		g_info.temp = clearBitChar(g_info.temp, g_info.i);
	g_info.i++;
	if (g_info.i == 8)
	{
		write(1, &g_info.temp, 1);
		g_info.i = 0;
	}
}

int	main(void)
{
	g_info.i = 0;
	printf("The sever PID: %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
