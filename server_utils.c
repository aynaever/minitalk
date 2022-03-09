/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:52:11 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/08 18:21:14 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	setBit(int	num, int k)
{
	return (num | (1 << k));
}

int	clearBit(int num, int k)
{
	return (num  & ~(1 << k));
}

unsigned char	setBitChar(unsigned char	num, int k)
{
	return (num | (1 << k));
}

unsigned char	clearBitChar(unsigned char num, int k)
{
	return (num  & ~(1 << k));
}
