NAME		=	philo

SRCS		=	error.c init.c main.c philo.c utils.c
				
OBJS		=	$(SRCS:.c=.o)

CC			=	cc

RM			=	rm -f

CFLAGS		=	-Wall -Werror -Wextra

all:		$(NAME)

%.o: %.c $(NAME).h
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean:		clean
	@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re