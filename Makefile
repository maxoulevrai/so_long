NAME = so_long

RED				= \e[31m
GREEN			= \e[32m
YELLOW			= \e[33m
BLUE			= \e[34m
MAGENTA			= \e[35m
CYAN			= \e[36m
RESET			= \e[m

SRCS_DIR = src/

LIB = lib/libft.a
SRCS = main.c \
		$(SRCS_DIR)map_parsing.c \
		$(SRCS_DIR)error_handling.c \
		$(SRCS_DIR)parsing_utils.c \
		$(SRCS_DIR)moves_hdl.c \
		$(SRCS_DIR)map_load.c \
		$(SRCS_DIR)so_long_utils.c 

OBJS = $(SRCS:%.c=build/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif

MLX_DIR = mlx/
MLX_LIB = mlx/libmlx_$(shell uname).a

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIB) $(MLX_LIB)
	@echo "$(GREEN)Linking $@$(NO_COLOR)"
	@$(CC) $(CFLAGS) -o $@ $^ $(MLX_FLAGS) 
	@echo "$(GREEN)Build complete$(NO_COLOR)"

$(LIB):
	@$(MAKE) -C lib lib

$(OBJS): | build

build:
	@mkdir -p build

build/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<$(NO_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

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

