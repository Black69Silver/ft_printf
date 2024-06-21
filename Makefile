# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 12:55:54 by ggeorgie          #+#    #+#              #
#    Updated: 2023/11/16 18:46:17 by ggeorgie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# '-c' to prevent relinking
# '$<' representing the updated source file(s)
# '-o' a compiler flag followed by the output file name
# '$@' representing the target/object file(s)
# 'ar' to create an archive
# '-r' to replace or add files to archive
# '-c' to suppress the diagnostic message that is written by default
# '-v' to produce verbose output
# '.PHONY' to avoid a file name conflict and improve performance

NAME	= libftprintf.a

SRC		= ft_printf.c \
		ft_print_dec.c \
		ft_print_hex.c \
		ft_print_out.c

OBJ		= $(SRC:.c=.o)

CC		= cc

CFLAGS	= -Wall -Werror -Wextra

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar -r -c -v $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean \
	all

.PHONY : all, clean, fclean, re
