/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:38:33 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/06 12:55:24 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

typedef struct	s_info
{
	int	len;
	int	cpid;
	int	count;
	char	*str;  
} t_info;

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int	getBit(int num, int k);
int	sendUchar(unsigned char c, pid_t pid);
int	sendNum(int	num, pid_t pid);

#endif

