/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:38:33 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/09 21:32:34 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_info
{
	int				spid;
	int				i;
	int				j;
	int				len;
	unsigned char	*str;
}	t_info;

int				get_bit(unsigned char num, int k);
void			send_uchar(unsigned char c, pid_t pid);
void			send_num(int num, pid_t pid);
unsigned char	set_bit_char(unsigned char num, int k);
unsigned char	clear_bit_char(unsigned char num, int k);
void			send_str(unsigned char	*str, pid_t pid);

#endif
