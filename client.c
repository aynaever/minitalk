/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:15:03 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/09 01:36:33 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int , char **argv)
{
	int	cpid;
	int	len;
	pid_t	spid;

	cpid = getpid();
	spid = atoi(argv[1]);
	len = strlen(argv[2]);
	ft_printf("the CPID: %d \n", cpid);
	ft_printf("the SPID: %d \n", spid);
	ft_printf("the len of the string: %d \n", len);
	//sendNum(cpid, spid);
	//sendNum(len, spid);
	sendStr((unsigned char *)argv[2], spid);
	return (0);
}
