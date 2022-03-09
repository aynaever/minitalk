# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaouadi <anaouadi@student.42wolfsbu       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 11:41:04 by anaouadi          #+#    #+#              #
#    Updated: 2022/03/08 23:10:39 by anaouadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Client #
CNAME = client # Name of the client
CSOURCE = client.c client_utils.c # Source files that make the client

# Server #
SNAME = server # Name of the server
SSOURCE = server.c server_utils.c  # Source files that make the server

# Compile #
CC = gcc # compiler that will comile the files
FLAGS = -Wall -Werror -Wextra -g # flags that will be used to compile source files

all: $(SNAME) $(CNAME)

$(CNAME): client.o client_utils.c ft_printf/libftprintf.a
	$(CC) $(FLAGS) $^ -o $@

$(SNAME): server.o server_utils.c ft_printf/libftprintf.a
	$(CC) $(FLAGS) $^ -o $@

ft_printf/libftprintf.a :
	make ft_printf/

client.o : client.c client_utils.c
	$(CC) $(FLAGS) -c $^

server.o : server.c server_utils.c
	$(CC) $(FLAGS) -c $^

clean :
	rm -rf *.o

fclean :
	rm -rf $(CNAME) $(SNAME) *.o

re : fclean all

no :
	norminette *.c *.h

.PHONY: all clean fclean no
