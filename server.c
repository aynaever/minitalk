/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:11:33 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/13 14:07:09 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	temp;
	static int				i;

	if (sig == SIGUSR2)
		temp = set_bit_char(temp, i);
	else if (sig == SIGUSR1)
		temp = clear_bit_char(temp, i);
	i++;
	if (i == 8)
	{
		write(1, &temp, sizeof(unsigned char));
		i = 0;
		temp = '\0';
	}
	kill(info->si_pid, SIGUSR2);
	(void)context;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("The sever PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
