/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:52:11 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/09 18:11:38 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	set_bit_char(unsigned char num, int k)
{
	return (num | (1 << k));
}

unsigned char	clear_bit_char(unsigned char num, int k)
{
	return (num & ~(1 << k));
}
