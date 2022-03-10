/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 07:07:04 by anaouadi          #+#    #+#             */
/*   Updated: 2022/03/10 14:52:08 by anaouadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		c_conv(va_list ptr);
int		s_conv(va_list ptr);
int		p_conv(va_list ptr);
int		d_conv(va_list ptr);
int		i_conv(va_list ptr);
int		u_conv(va_list ptr);
int		x_conv(va_list ptr);
int		xx_conv(va_list ptr);
int		choose_conv(va_list ptr, char c);
int		ft_printf(const char *str, ...);
void	ft_putptr(unsigned long long int n);
void	ft_putnbr(int n);
void	ft_putnbru(unsigned int n);
void	ft_puthex(unsigned int n);
void	ft_puthe_x(unsigned int n);
int		ft_size_nbr(int n);
int		ft_size_nbru(unsigned int n);
int		ft_size_nbrx(unsigned int n);
int		ft_size_nbrp(unsigned long long int n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

#endif
