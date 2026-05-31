# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 22:34:29 by alex              #+#    #+#              #
#    Updated: 2026/05/31 03:14:27 by alejandro        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

FILE_NAME = push-swap-presentacion
SRC_FILE = src
INCLUDE = Include

SRCS = $(SRC_FILE)/push_swap.c $(SRC_FILE)/parse_arguments.c \
		$(SRC_FILE)/circular_buffer_utils.c $(SRC_FILE)/utils.c \
		$(SRC_FILE)/short_stacks.c $(SRC_FILE)/moves.c \
		$(SRC_FILE)/moves2.c $(SRC_FILE)/budget.c $(SRC_FILE)/budget_utils.c \
		$(SRC_FILE)/do_moves.c $(SRC_FILE)/do_moves_utils.c \
		$(SRC_FILE)/actualize_data.c 
LIBFT_DIR = $(INCLUDE)/libft

OBJS = $(SRCS:.c=.o)

HEADERS = push_swap.h
LIBFT = libft.a

all: $(LIBFT) $(NAME)
	@echo "    _    _     ____    _    ____  ____  ___ _     "
	@echo "   / \\  | |   / ___|  / \\  |  _ \\|  _ \\|_ _| |    "
	@echo "  / _ \\ | |  | |     / _ \\ | |_) | |_) || || |    "
	@echo " / ___ \\| |__| |___ / ___ \\|  _ <|  _ < | || |___ "
	@echo "/_/   \\_\\_____\\____/_/   \\_\\_| \\_\\_| \\_\\___|_____|"
	@echo " La carpeta predefinida es: $(FILE_NAME). Si quieres cambiarla pon el nombre de la carpeta que contiene al proyecto EJ: make FILE_NAME="nombre de tu carpeta" "

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(SRC_FILE) -L$(LIBFT_DIR) -lft -o $(NAME)


%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): 
	make all -C $(INCLUDE)/libft

libft:
	make all -C $(INCLUDE)/libft

clean:
	make clean -C $(INCLUDE)/libft
	rm -f $(OBJS) $(BONUS_OBJS)
	
fclean: clean
	make fclean -C $(INCLUDE)/libft
	rm -f $(NAME)

re: fclean all

PHONY: make clean fclean re bonus