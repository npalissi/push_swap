NAME        := checker

DIR_LIB     =  ../lib

PRINTF_DIR  =  $(DIR_LIB)/printf
PRINTF_LIB  := $(PRINTF_DIR)/libftprintf.a

LIBFT_DIR   =  $(DIR_LIB)/libft
LIBFT_LIB   := $(LIBFT_DIR)/libft.a

GNL_DIR     = $(DIR_LIB)/gnl
GNL_LIB     = $(GNL_DIR)/gnl.a

SRCS =  main.c\
        get_stack.c \
        clean_exit.c\
        parse_arg.c\
        ../function_push_swap/ft_function_a.c\
        ../function_push_swap/ft_function_b.c\
        ../function_push_swap/ft_function_ba.c\
        ../function_push_swap/ft_function_shared.c\

OBJS = $(SRCS:.c=.o)

CC := cc
FLAGS := -Wall -Wextra -Werror -g

DEPS = ../push_swap.h

all: $(NAME)

# Ajoutez les dépendances sur les .h
$(NAME): $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB) $(GNL_LIB)
	echo "Compilation de $(NAME)..."
	$(CC) $(FLAGS) -o $@ $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB) $(GNL_LIB)

# Règle de compilation des .o avec dépendance sur les headers
%.o: %.c $(DEPS)
	$(CC) $(FLAGS) -c $< -o $@

$(PRINTF_LIB):
	echo "Compilation de la bibliothèque printf..."
	make -s -C $(PRINTF_DIR)

$(LIBFT_LIB):
	echo "Compilation de la bibliothèque libft..."
	make -s -C $(LIBFT_DIR)

$(GNL_LIB):
	echo "Compilation de la bibliothèque get_next_line..."
	make -s -C $(GNL_DIR)

clean:
	echo "Nettoyage des fichiers objets..."
	make clean -s -C $(PRINTF_DIR)
	make clean -s -C $(LIBFT_DIR)
	make clean -s -C $(GNL_DIR)
	rm -f $(OBJS)

fclean: clean
	echo "Suppression des exécutables..."
	make fclean -s -C $(PRINTF_DIR)
	make fclean -s -C $(GNL_DIR)
	make fclean -s -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re