#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/03/07 09:32:29 by nhuber            #+#    #+#             *#
#*   Updated: 2016/03/29 15:18:39 by nhuber           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = get_next_line
L_DIR = project/libft
F_DIR = project/
M_DIR = ./
FILES = $(M_DIR)/main.c $(F_DIR)/get_next_line.c

TMP = Makefile~  $(F_DIR)/get_next_line.h~ $(NAME)~ $(FILES:.c=.c~)

all : $(NAME)

$(NAME) :
	@echo Project : $(NAME)
	@echo "\t"- Compiler : $(CC)
	@echo "\t"- Flags : $(FLAGS)
	@$(CC) -o $(NAME) $(FLAGS) $(FILES) -I $(L_DIR) -L $(L_DIR) -lft

clean :
	@echo clean :"\n\tTemporary files deteleted"
	@rm -f $(TMP)

fclean : clean
	@echo fclean :"\n\tExec file deleted"
	@rm -f $(NAME)

test :
	@echo Executing test :
	@$(CC) -o $(NAME) $(FLAGS) mainb.c $(F_DIR)/get_next_line.c -I $(L_DIR) -L $(L_DIR) -lft
	@./$(NAME)

re : fclean all
