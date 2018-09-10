#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 14:04:34 by gbrandon          #+#    #+#              #
#    Updated: 2018/09/10 14:07:17 by gbrandon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME= bsq
LIBR= ft_str.a
LIB_SRCS= $(wildcard lib/*c)
LIB_OBJS= $(patsubst %.c,%.o,$(LIB_SRCS))
SRCS= $(wildcard *.c)
HEADERS= includes
DIR_SRCS= srcs

all: $(NAME)

$(NAME): $(DIR_SRCS)/$(SRCS) lib$(LIBR)
	gcc -Wall -Wextra -Werror -I$(HEADERS) -L. -lft_str $(DIR_SRCS)/$(SRCS) -o $@

lib$(LIBR): $(LIB_OBJS)
	ar rc lib$(LIBR) $(LIB_OBJS)

%.o: %.c
	gcc -Wall -Wextra -Werror -I$(HEADERS) -c $< -o $@

clean:
	rm -rf *.o
	rm -rf lib/*.o

fclean: clean
	rm -rf $(NAME)
	rm -rf lib$(LIBR)

re: fclean all