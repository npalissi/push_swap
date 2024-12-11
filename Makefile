NAME        := push_swap

DIR_LIB     =   lib
DIR_BONUS   =   bonus

PRINTF_DIR  =  $(DIR_LIB)/printf
PRINTF_LIB  := $(PRINTF_DIR)/libftprintf.a
LIBFT_DIR   =  $(DIR_LIB)/libft
LIBFT_LIB   := $(LIBFT_DIR)/libft.a
BONUS_DIR   =  $(DIR_BONUS)/bonus
BONUS_LIB   := $(BONUS_DIR)/checker

SRCS =  srcs/main.c\
        srcs/get_stack.c \
        srcs/clean_exit.c\
        srcs/parse_arg.c\
        srcs/start_sort.c\
        function_push_swap/ft_function_a.c\
        function_push_swap/ft_function_b.c\
        function_push_swap/ft_function_ba.c\
        function_push_swap/ft_function_shared.c\
        srcs/algo/ft_turkish.c\
        srcs/ft_quicksort/quicksort.c\
        srcs/ft_quicksort/quicksort_five.c\
        srcs/algo/ft_utils.c\
        srcs/algo/ft_operator.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

CC := cc
FLAGS := -Wall -Wextra -Werror -g
INCLUDE = -I.

# .SILENT:

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -MMD -c $< -o $@

$(PRINTF_LIB):
	make -s -C $(PRINTF_DIR)

$(LIBFT_LIB):
	make -s -C $(LIBFT_DIR)

clean:
	make clean -s -C $(PRINTF_DIR)
	make clean -s -C $(LIBFT_DIR)
	make clean -s -C $(DIR_BONUS)    
	rm -f $(OBJS) $(DEPS)

fclean: clean
	make fclean -s -C $(PRINTF_DIR)
	make fclean -s -C $(LIBFT_DIR)
	make fclean -s -C $(DIR_BONUS)
	rm -f $(NAME)

bonus: $(BONUS_LIB)

$(BONUS_LIB):
	make -s -C $(DIR_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus