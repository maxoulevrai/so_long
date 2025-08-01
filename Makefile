NAME = push_swap

RED				= \e[31m
GREEN			= \e[32m
YELLOW			= \e[33m
BLUE			= \e[34m
MAGENTA			= \e[35m
CYAN			= \e[36m
RESET			= \e[m

LIB = lib/libft.a

SRCS = main.c \
		sort/sort_algo.c \
		sort/sort_utils.c \
		sort/tiny_sort.c \
		utils/init_utils.c \
		utils/parsing_utils.c \
		utils/linked_list_utils.c \
		utils/instructions/swap_instructions.c \
		utils/instructions/push_instructions.c \
		utils/instructions/rotate_instructions.c \
		utils/instructions/reverse_rotate_instructions.c

OBJS = $(SRCS:%.c=build/%.o)
DEPS = $(OBJS:.o=.d)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -MMD

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	@echo "$(GREEN)Linking $@$(NO_COLOR)"
	@$(CC) $(CFLAGS) -o $@ $^
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
