# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmisnich <dmisnich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/18 12:37:43 by dmisnich          #+#    #+#              #
#    Updated: 2018/01/26 11:39:24 by dmisnich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS =  -Wall -Wextra -Werror -O3 -I ./includes/
SRCS =	./src/main.c \
		./src/exit.c \
		./fractols/mandelbrot.c \
		./fractols/mandelbrot_5.c \
		./fractols/julia.c \
		./src/put_pixel.c \
		./src/keyboard.c \
		./src/parse.c \
		./fractols/buffalo.c \
		./fractols/mandelbar.c \
		./fractols/burningship.c \

OBJ = $(SRCS:.c=.o)

#libft
LFT_DIR = ./libft/
LFT_LNK = -L $(LFT_DIR) -lft

#minilibx
MLX_LNK = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_DIR)
	$(CC) $(CFLAGS) $(MLX_LNK) $(LFT_LNK) $(OBJ) -g -o $(NAME)

clean:
	make -C $(LFT_DIR) clean
	rm -f src/*.o
	rm -f fractols/*.o

fclean: clean
	make -C $(LFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
