NAME = so_long

RED				= \e[31m
GREEN			= \e[32m
YELLOW			= \e[33m
BLUE			= \e[34m
MAGENTA			= \e[35m
CYAN			= \e[36m
RESET			= \e[m

LIB = lib/libft.a

SRCS = main.c \

OBJS = $(SRCS:%.c=build/%.o)
DEPS = $(OBJS:.o=.d)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAG = -Lmlx_linux -lmlx -lX11 -lXext

MLX_DIR = mlx_linux/
MLX_LIB = mlx_linux/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIB) $(MLX_LIB)
	@echo "$(GREEN)Linking $@$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(MLXFLAG) -o $@ $^
	@echo "$(GREEN)Build complete$(NO_COLOR)"

$(LIB):
	@$(MAKE) -C lib lib

$(OBJS): | build

build:
	@mkdir -p build

build/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<$(NO_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files$(NO_COLOR)"
	@rm -rf build
	@$(MAKE) -C lib lib_clean

fclean: clean
	@echo "$(RED)Cleaning executable$(NO_COLOR)"
	@rm -f $(NAME)
	@$(MAKE) -C lib lib_fclean

re: fclean all

.PHONY: all clean fclean re 

-include $(DEPS)
