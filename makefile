NAME = so_long

CC = gcc
LIB = libft.a
LIB_DIR = libft/
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -g

SRCS = move_player.c so_long.c checker.c draw_tools.c executer.c extra_tools.c parser.c
SRCS_OBJS = ${SRCS:.c=.o}

# BONUS_NAME = 
# BONUS = 
# BONUS_OBJ = 

all : $(NAME)

$(LIB) :
	@echo "${GREEN}====================================="
	make -C $(LIB_DIR) --silent
	cp libft/$(LIB) ./

$(NAME) : $(LIB) $(SRCS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SRCS) $(LIB) -o $(NAME)
	@echo "\n====== $(NAME) compiling finished ======"
	@echo "==========================================${NC}\n"

bonus : $(LIB) $(BONUS)
	@echo "${MAGENTA}====================================="
	$(CC) $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)
	$(CC) $(CFLAGS) $(BONUS) $(LIB) -o $(BONUS_NAME)
	@echo "\n====== $(BONUS_NAME) compiling finished ======"
	@echo "==========================================\n${NC}"



clean :
	@echo "${RED}====================================="
	rm -f *.o
	@echo "====== object files removed ======"
	@echo "===================================${NC}\n"

fclean : clean
	@echo "${YELLOW}====================================="
	rm -f $(NAME) $(BONUS_NAME)
	rm -f $(LIB)
	make fclean -C $(LIB_DIR) --silent
	rm -rf $(NAME).dSYM
	rm -rf $(BONUS_NAME).dSYM
	@echo "\n====== binary files removed ======="
	@echo "=====================================\n${NC}"

re : fclean all

.PHONY : all clean fclean re