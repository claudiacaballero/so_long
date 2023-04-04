# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 16:28:40 by ccaballe          #+#    #+#              #
#    Updated: 2023/04/04 16:37:21 by ccaballe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror -MMD
SRC = so_long.c map_checker.c 

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
RM = rm -f

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

LIBS = ft_printf/libftprintf.a libft/libft.a

%.o: %.c Makefile
	@$(CC) $(CFLAGS) -I./ -c $< -o $@

all: 
	@$(MAKE) -C libft
	@$(MAKE) -C ft_printf
	@$(MAKE) $(NAME)

$(NAME):: $(OBJS)
	@$(MAKE) -C libft
	@$(MAKE) -C ft_printf
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@
	@echo "$(GREEN)so_long compiled$(NC)"

$(NAME)::
	@echo -n

clean:
	@$(RM) $(OBJS) $(DEPS)
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C ft_printf
	@echo "$(RED)\ndestruction successful\n$(NC)"

fclean: clean
	@$(RM) $(NAME) $(LIBS) 

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)