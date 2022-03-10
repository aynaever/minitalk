# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 16:12:07 by anaouadi          #+#    #+#              #
#    Updated: 2021/08/27 11:59:47 by anaouadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = ft_putstr_fd.c ft_putchar_fd.c conv_utils_basic.c conv_utils_extend.c conv_utils_help.c conv_utils_size.c ft_printf.c
OBJS = $(SRCS:.c=.o)
CC = gcc

all : $(NAME)

$(NAME) : $(OBJS) 
	ar -crs $(NAME) $(OBJS) 
	
$(OBJS) : $(SRCS) ft_printf.h
	$(CC) -c $(SRCS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
