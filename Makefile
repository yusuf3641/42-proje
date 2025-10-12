NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = main.c stack_core.c stack_utils.c array/array1.c array/argv_check.c array/argv_check2.c array/string_utils.c array/string_utils2.c \
change/change_top_ab.c change/change_top2_swap.c rotate/rotate_down_up.c rotate/rotate_up_down_ab.c sort/is_sorted.c \
sort/is_sorted2.c radix_algorithm/bite.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
