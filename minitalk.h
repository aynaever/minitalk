/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:38:33 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/10 13:49:26 by anaouadi         ###   ########.fr       */
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
unsigned char	set_bit_char(unsigned char num, int k);
unsigned char	clear_bit_char(unsigned char num, int k);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *nptr);

#endif
