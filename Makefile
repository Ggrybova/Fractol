#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile1                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/05 12:04:09 by ggrybova          #+#    #+#              #
#    Updated: 2017/06/17 13:33:48 by ggrybova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAMELIB = libft.a

SRC = mandelbrot.c fractals.c hook_func.c julia.c newton.c main.c

OBJ		= $(SRC:.c=.o)

CC		= gcc
CFLAGS  = -Wall -Wextra -Werror
RM 		= rm -f

LIBDIR  = ./libft/
INCDIR	= ./


FLG = -lmlx -framework OpenGL -framework AppKit

all: obj $(NAME)

obj:
	mkdir -p $(LIBDIR)

$(INDIR)%.o: $(INDIR)%.c
	$(CC)  $(CFLAGS)  -I $(INCDIR) -c $< -o $@ 

$(NAME): $(NAMELIB) $(OBJ)
	$(CC) $(FLG) -o $(NAME) $(OBJ) -L. -lft

$(NAMELIB):
	cd $(LIBDIR); make; make clean; mv $(NAMELIB) ../;

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	$(RM) $(NAME) $(NAMELIB)

re: fclean all
