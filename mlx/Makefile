# #
# #

# NOM = libmlx.a
# SRC = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
# SRC += mlx_png.c mlx_mouse.m
# OBJ1 = $(SRC:.c=.o)
# OBJ = $(OBJ1:.m=.o)
# CFLAGS += -O2 -Wno-deprecated-declarations

# # add to match string put with X11 in size and position
# CFLAGS += -DSTRINGPUTX11

# all: $(NOM)

# $(NOM):	$(OBJ)
# 	@ar -r $(NOM) $(OBJ)
# 	@ranlib $(NOM)

# clean:
# 	@rm -f $(NOM) $(OBJ) *~
# 	@rm -f mlx_app

# re: clean all

#<---COLORS--->#
GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

#<---NAME--->#
NOM		=	libmlx.a

#<---SRC && OTHERS--->#
OBJ_DIR	=	./obj/

SRC_C	=	mlx_shaders.c mlx_xpm.c mlx_int_str_to_wordtab.c
SRC_M	= 	mlx_new_image.m mlx_new_window.m mlx_init_loop.m

OBJ_C	=	$(addprefix $(OBJ_DIR)src_c/, $(SRC_C:%.c=%.o)) #$(SRC_C:%.c=%.o) 
OBJ_M	=	$(addprefix $(OBJ_DIR)src_m/, $(SRC_M:%.m=%.o)) #$(SRC_M:%.m=%.o) 

CFLAGS	+=	-O2 -Wno-deprecated-declarations -DSTRINGPUTX11

MDP		=	mkdir -p

#<---RULES--->#
$(OBJ_DIR)src_c/%.o: %.c Makefile
	@$(MDP) $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)src_m/%.o: %.m Makefile
	@$(MDP) $(dir $@)
	@$(CC) -MT $@ $(CFLAGS) -MMD -MP -c $< -o $@

all		:
	@$(MAKE) $(NOM)

$(NOM)::	$(OBJ_C) $(OBJ_M)
	@ar -crs $@ $(OBJ_C) $(OBJ_M)
	@#ranlib $@
	@echo "$(GREEN)mlx compiled$(NC)"
$(NOM)::
	@echo -n

clean	:
	@rm -rf $(OBJ_DIR) *~
	@rm -f mlx_app
	@echo "$(RED)mlx objects deleted$(NC)"

fclean	:
	@$(MAKE) clean
	@$(RM) $(NOM)
	@echo "$(RED)mlx exec deleted$(NC)"

re: fclean all

.PHONY:	all clean fclean re