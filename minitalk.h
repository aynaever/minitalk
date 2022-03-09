/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:38:33 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/09 01:36:50 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

typedef struct	s_info
{
	int	len;
	int	cpid;
	int	count;
	int	i;
	unsigned char	temp;
} t_info;

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "./ft_printf/ft_printf.h"

int	getBit(int num, int k);
void	sendUchar(unsigned char c, pid_t pid);
void	sendNum(int	num, pid_t pid);
int	setBit(int	num, int k);
int	clearBit(int num, int k);
unsigned char	setBitChar(unsigned char num, int k);
unsigned char	clearBitChar(unsigned char num, int k);
void	sendStr(unsigned char	*str, pid_t pid);

#endif

