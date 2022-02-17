# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 15:23:37 by rgirondo          #+#    #+#              #
#    Updated: 2021/09/16 21:15:01 by rgirondo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex

CC=gcc

CFLAGS=-Wall -Wextra -Werror

HEADER=pipex.h

RM=rm -f

SRC= ./ft_split.c ./ft_strjoin.c ./ft_strnstr.c  ./pipex.c

OBJ=$(SRC:%.c=%.o)

all:$(NAME)

$(NAME): $(OBJ) $(HEADER)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ) $(OBJ2)

fclean: clean
		$(RM)
		rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
