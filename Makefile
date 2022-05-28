CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c tools.c tools_2.c lists_tools.c lists_tools_2.c protection_tools.c instructions.c small_sort_tools.c sort_tools.c big_sort_tools.c

PUSH_SWAP_H = push_swap.h 

PUSH_SWAP_A = push_swap.a

NAME = push_swap.a

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	rm -f $(BONUS)
	ar rc $(NAME) $(OBJS) $(PUSH_SWAP_A) $(PUSH_SWAP_H)
	$(CC) $(CFLAGS) $(NAME) -o push_swap

re: fclean all

clean:
	rm -f $(NAME)
	rm -f *.o 

fclean:	clean
	rm -f push_swap

.PHONY: clean fclean re all