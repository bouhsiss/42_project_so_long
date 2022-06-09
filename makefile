RED = \033[0;31m
NC = \033[0m	
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m

NAME = so_long

CC = gcc
LIB = libft.a
LIB_DIR = libft/
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit #-g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -g

SRCS = srcs/move_player.c srcs/so_long.c srcs/checker.c srcs/draw_tools.c srcs/executer.c srcs/extra_tools.c srcs/parser.c

BONUS_NAME = so_long_bonus
BONUS = bonus/move_player_bonus.c bonus/so_long_bonus.c bonus/checker_bonus.c bonus/draw_tools_bonus.c bonus/executer_bonus.c \
		bonus/extra_tools_bonus.c bonus/parser_bonus.c

all : $(NAME)

$(LIB) :
	@echo "${GREEN}====================================="
	make -C $(LIB_DIR) --silent
	cp libft/$(LIB) ./

$(NAME) : $(LIB)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SRCS) $(LIB) -o $(NAME)
	@echo "\n====== $(NAME) compiling finished ======"
	@echo "==========================================${NC}\n"

bonus : $(LIB)
	@echo "${MAGENTA}====================================="
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(BONUS) $(LIB) -o $(BONUS_NAME)
	@echo "\n====== $(BONUS_NAME) compiling finished ======"
	@echo "==========================================\n${NC}"



clean :
	@echo "${RED}====================================="
	make fclean -C $(LIB_DIR) --silent
	@echo "====== object files removed ======"
	@echo "===================================${NC}\n"

fclean : clean
	@echo "${YELLOW}====================================="
	rm -f $(NAME) $(BONUS_NAME)
	rm -f $(LIB)
	rm -rf $(NAME).dSYM
	rm -rf $(BONUS_NAME).dSYM
	@echo "\n====== binary files removed ======="
	@echo "=====================================\n${NC}"

re : fclean all

.PHONY : all clean fclean re