# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 10:58:39 by alicifer          #+#    #+#              #
#    Updated: 2024/02/12 13:22:13 by alicifer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
OBJ_DIR = obj/

SRC =	ft_atoi\
		ft_bzero\
		ft_calloc\
		ft_isalnum\
		ft_isalpha\
		ft_isascii\
		ft_isdigit\
		ft_isprint\
		ft_itoa\
		ft_memchr\
		ft_memcmp\
		ft_memcpy\
		ft_memmove\
		ft_memset\
		ft_putchar_fd\
		ft_putendl_fd\
		ft_putnbr_fd\
		ft_putstr_fd\
		ft_putstring\
		ft_split\
		ft_strchr\
		ft_strdup\
		ft_striteri\
		ft_strjoin\
		ft_strlcat\
		ft_strlcpy\
		ft_strlen\
		ft_strmapi\
		ft_strncmp\
		ft_strnstr\
		ft_strrchr\
		ft_strtrim\
		ft_strtrim\
		ft_substr\
		ft_tolower\
		ft_toupper\
		
SRC_B = ft_lstnew_bonus\
        ft_lstadd_front_bonus\
        ft_lstsize_bonus\
        ft_lstlast_bonus\
        ft_lstadd_back_bonus\
        ft_lstdelone_bonus\
		ft_lstclear_bonus\
		ft_lstiter_bonus\
		ft_lstmap_bonus\

GNL = 	get_next_line_utils\
		get_next_line\
		ft_strjoin_gnl\
	
PRINTF =	ft_printf\
			ft_pointer\
			ft_hexa_to_str\
			ft_print_format\
			ft_putchar\
			ft_puthexa\
			ft_putnumber\
			ft_putunsigned\
			ft_unsign_itoa\
							

INCLUDE = libft.h

OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))
OBJ_B = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_B)))
OBJ_GNL = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(GNL)))
OBJ_PRINTF = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(PRINTF)))

OBJF = .cache_exists



$(NAME): $(OBJS) $(INCLUDE)
	ar rcs	$(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME) bonus gnl ptf

$(OBJF): 
	@mkdir -p $(OBJ_DIR)
	
bonus: $(OBJ_B)
	ar crs $(NAME) $(OBJ_B) 

gnl: $(OBJ_GNL)
	@ar rcs $(NAME) $(OBJ_GNL)

ptf: $(OBJ_PRINTF)
	@ar rcs $(NAME) $(OBJ_PRINTF)

clean:
	rm -frf $(OBJ_DIR)

	
fclean:	clean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME) 
	
re: fclean all

.PHONY: all bonus clean flean re gnl ptf
