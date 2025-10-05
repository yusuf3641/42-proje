# **************************************************************************** #
#                                   Makefile                                   #
# **************************************************************************** #

NAME    = push_swap.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
INCS    = -I .

OBJ_DIR = .obj
MKDIR   = mkdir -p
RM      = rm -rf

# Explicit source list (no wildcard)
SRCS = \
	main.c \
	stack_core.c \
	stack_utils.c \
	array/array1.c \
	array/argv_check.c \
	array/argv_check2.c \
	change/change_top_ab.c \
	change/change_top2_swap.c \
	rotate/rotate_down_up.c \
	rotate/rotate_up_down_ab.c \
	sort/is_sorted.c \
	sort/is_sorted2.c \
	radix_algorithm/bite.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c push_swap.h
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
