# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 16:28:40 by ccaballe          #+#    #+#              #
#    Updated: 2023/05/03 15:32:38 by ccaballe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror -MMD
FILES = so_long.c map_checker.c path_finder.c events.c

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(FILES))

OBJ_DIR = objects/
OBJS = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))
DEPS = $(addprefix $(OBJ_DIR), $(FILES:.c=.d))
RM = rm -rf

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

LIBS = libs/libft/libft.a libs/mlx/libmlx.a

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I./ -c $< -o $@

all:
	@$(MAKE) -C libs/libft --no-print-directory
	@$(MAKE) -C libs/mlx --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(NAME):: $(OBJS)
	
	@$(CC) -framework OpenGL -framework Appkit $(CFLAGS) $(OBJS) $(LIBS) -o $@
	@echo "$(GREEN)so_long compiled$(NC)"

$(NAME)::
	@echo -n

clean:
	@$(RM) $(OBJ_DIR) --no-print-directory
	@$(MAKE) clean -C libs/libft --no-print-directory
	@$(MAKE) clean -C libs/mlx --no-print-directory
	@echo "$(RED)\ndestruction successful\n$(NC)"

fclean: clean
	@$(RM) $(NAME) $(LIBS) 

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)