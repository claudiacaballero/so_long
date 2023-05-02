# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 16:28:40 by ccaballe          #+#    #+#              #
#    Updated: 2023/05/02 12:58:55 by ccaballe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror -MMD
SRC = so_long.c map_checker.c path_finder.c events.c

OBJ_DIR = objects/
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEPS = $(addprefix $(OBJ_DIR), $(SRC:.c=.d))
RM = rm -rf

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

LIBS = libft/libft.a mlx/libmlx.a

$(OBJ_DIR)%.o: %.c Makefile
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I./ -c $< -o $@

all:
	@$(MAKE) -C libft --no-print-directory
	@$(MAKE) -C mlx --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(NAME):: $(OBJS)
	
	@$(CC) -framework OpenGL -framework Appkit $(CFLAGS) $(OBJS) $(LIBS) -o $@
	@echo "$(GREEN)so_long compiled$(NC)"

$(NAME)::
	@echo -n

clean:
	@$(RM) $(OBJ_DIR) --no-print-directory
	@$(MAKE) clean -C libft --no-print-directory
	@$(MAKE) clean -C mlx --no-print-directory
	@echo "$(RED)\ndestruction successful\n$(NC)"

fclean: clean
	@$(RM) $(NAME) $(LIBS) 

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)