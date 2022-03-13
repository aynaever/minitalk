/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:15:03 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/13 14:22:24 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_info;

void	handler(int sig)
{
	if (g_info.j == 8)
	{
		g_info.j = 0;
		g_info.i++;
	}
	if (g_info.len == g_info.i)
		exit(0);
	if (get_bit(g_info.str[g_info.i], g_info.j++) == 0)
	{
		if (kill(g_info.spid, SIGUSR1) == -1)
			g_info.inv = 1;
	}
	else
	{	
		if (kill(g_info.spid, SIGUSR2) == -1)
			g_info.inv = 1;
	}
	(void)sig;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					cpid;

	cpid = getpid();
	g_info.spid = ft_atoi(argv[1]);
	g_info.len = ft_strlen(argv[2]);
	g_info.i = 0;
	g_info.j = 0;
	g_info.str = (unsigned char *) argv[2];
	sa.sa_handler = handler;
	ft_printf("the CPID: %d \n", cpid);
	ft_printf("the SPID: %d \n", g_info.spid);
	ft_printf("the len of the string: %d \n", g_info.len);
	sigaction(SIGUSR2, &sa, NULL);
	handler(0);
	if (g_info.inv == 1 || argc != 3)
	{
		ft_printf("Invalid PID or Empty Text!");
		return (0);
	}
	while (1)
		pause();
	return (argc);
}
