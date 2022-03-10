/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:15:03 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/10 13:06:26 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info g_info;

void	handler(int sig, siginfo_t *info, void *context)
{
	if (g_info.j == 8)
	{
		g_info.j = 0;
		g_info.i++;
	}
	//ft_printf("received SIGUSR2\n");
	//ft_printf("g_info.spid = %d \n", info->si_pid);
	if (g_info.len == g_info.i)
		exit(0);
	if (get_bit(g_info.str[g_info.i], g_info.j++) == 0)
		kill(g_info.spid, SIGUSR1);
	else
		kill(g_info.spid, SIGUSR2);
	(void)sig;
	(void)context;
	(void)info;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					cpid;

	cpid = getpid();
	g_info.spid = atoi(argv[1]);
	g_info.len = strlen(argv[2]);
	g_info.i = 0;
	g_info.j = 0;
	g_info.str = (unsigned char*) argv[2];
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("the CPID: %d \n", cpid);
	ft_printf("the SPID: %d \n", g_info.spid);
	ft_printf("the len of the string: %d \n", g_info.len);
	sigaction(SIGUSR2, &sa, NULL);
	handler(0, NULL, NULL);
	while (1)
		pause();
	return (argc);
}
