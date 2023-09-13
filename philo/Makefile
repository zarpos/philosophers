# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 15:19:02 by drubio-m          #+#    #+#              #
#    Updated: 2023/09/13 12:12:04 by drubio-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
FLAGS = -Wall -Wextra -Werror #-g3  -fsanitize=address
SRC = philo.c lib_utils.c parse_params.c
OBJ_FOLDER = obj
OBJS = $(addprefix $(OBJ_FOLDER)/, $(SRC:%.c=%.o))
RM = rm -rf



all: $(NAME) $(OBJ_FOLDER)

.SILENT:

$(NAME): $(OBJS)     
	@echo "\033[1;95m"  ' ________  ___  ___  ___  ___       ________      '
	@echo 		  		' |\   __  \|\  \|\  \|\  \|\  \     |\   __  \     '
	@echo 		  		' \ \  \|\  \ \  \\\  \ \  \ \  \    \ \  \|\  \    '
	@echo 		  		'  \ \   ____\ \   __  \ \  \ \  \    \ \  \\\  \   '
	@echo 		  		'   \ \  \___|\ \  \ \  \ \  \ \  \____\ \  \\\  \  '
	@echo 		  		'    \ \__\    \ \__\ \__\ \__\ \_______\ \_______\ '
	@echo 				'     \|__|     \|__|\|__|\|__|\|_______|\|_______| '
	@echo "\033[0m\n"
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)   

$(OBJ_FOLDER)/%.o: %.c
	@mkdir -p $(OBJ_FOLDER)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_FOLDER)
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)
	@echo "\033[35;49;1mHEAVY CLEANING, EVERYTHING HAS BEEN DELETED\n"

re:	fclean all
	@echo "\033[33;49;1;3m\nEaster Egg ;)"
	
.PHONY:	all clean fclean re

# Este es el nuevo makefile
