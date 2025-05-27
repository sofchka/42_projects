NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SRC			= errors.c \
			  ft_sort.c \
			  ft_init_a.c \
			  ft_init_b.c \
			  ft_push.c \
			  ft_rev_rotate.c \
			  ft_rotate.c \
			  ft_stack_functions.c \
			  ft_swap.c \
			  libft_split.c \
			  libft_strlen_strlcpy_atoi.c \
			  utils.c \
			  push_swap.c

OBJ			= $(SRC:.c=.o)
INCLUDES	= -I.

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
