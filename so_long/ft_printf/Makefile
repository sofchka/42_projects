NAME = libftprintf.a

SRCS = ft_printf.c ft_print_functions.c
OBJS = $(SRCS:.c=.o)
INClUDE = -I

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror $(INCLUDE) 

all : $(NAME)

%.o:	%.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)
clean :
		$(RM) $(OBJS)
fclean : clean
		$(RM) $(NAME)

re :	fclean all

.PHONY:	all clean fclean re
