# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 11:41:04 by anaouadi          #+#    #+#              #
#    Updated: 2022/03/06 12:26:32 by anaouadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
SNAME = server
CC = gcc
FLAGS = -Wall -Werror -Wextra
SOURCE = server.c

all: $(SNAME) $(NAME)

$(NAME): client.o
	$(CC) $(FLAGS) $^ -c $@

$(SNAME): server.o
	$(CC) $(FLAGS) $^ -o $@

server.o : server.c
	$(CC) $(FALGS) -c $^

clean :
	rm -rf *.o

fclean :
	rm -rf $(NAME) $(SNAME) *.o

re : fclean all

no :
	norminette *.c *.h

.PHONY: all clean fclean no


	


