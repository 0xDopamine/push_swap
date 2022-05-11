CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c tools.c

LIBFT_H = libft.h 

LIBFT_A = libft.a

NAME = mandatory.a

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	rm -f $(BONUS)
	ar rc $(NAME) $(OBJS) $(LIBFT_A) $(LIBFT_H)
	$(CC) $(CFLAGS) $(NAME) -o push_swap

re: fclean all

clean:
	rm -f $(NAME)
	rm -f *.o 

fclean:	clean
	rm -f push_swap

.PHONY: clean fclean re all