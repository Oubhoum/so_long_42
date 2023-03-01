# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 20:52:32 by aoubhoum          #+#    #+#              #
#    Updated: 2023/02/17 22:15:10 by aoubhoum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SOURCES = get_next_line.c get_next_line_utils.c function.c so_long.c parsing.c so_long_utils.c \
		controller.c chech_valid_path.c hook_handler.c \

OBJECTS = $(SOURCES:.c=.o)
LIBFT = libft/libft.a
LIBFT_DIR = libft/
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) so_long.h 
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
%.o: %.c so_long.h
	$(CC) -c $(CFLAGS)  $<

$(LIBFT) : 
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
