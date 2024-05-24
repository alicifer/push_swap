# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alicifer <alicifer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 11:38:22 by alicifer          #+#    #+#              #
#    Updated: 2024/05/23 12:37:12 by alicifer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = gcc
CFLAGS = -Wextra -Wall -Werror -g
LIBFT = ./my_libft
SRC_DIR = src/
OBJ_DIR = obj/

SRC_FILES = main error utils  stack checkargs swap rev_rotate rotate push sort sort2 makemoves

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF = .cache_exists

all: $(NAME)

$(NAME):	$(OBJ)
			@make all -C $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -o $(NAME)
			
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			
clean:
			@${MAKE} -C ./my_libft fclean
			@rm -frf $(OBJ_DIR)
		

fclean:		clean
			@rm -rf $(NAME)

re: fclean all

norm:
			@norminette $(SRC_DIR)
			@norminette $(LIBFT)
						
.PHONY: all clean fclean re norm