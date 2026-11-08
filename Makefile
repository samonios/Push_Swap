NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a
INCLUDES    = -I. -I$(LIBFT_DIR)

COMMON_SRCS = parser/flags.c \
              parser/input_validation.c \
              parser/parser_arg.c \
              parser/error.c \
              do_operations/do_op.c \
              do_operations/push.c \
              do_operations/r_rotate.c \
              do_operations/rotate.c \
              do_operations/swap.c \
              utils/set_target.c \
              utils/utils_nico.c \
              utils/free_struct.c \
              strategies/benchmark.c \
              strategies/select_strategy.c \
              strategies/adaptive/adaptive_sort.c \
              strategies/simple/min_extraction_sort.c \
              strategies/complex/quick_sort.c \
              strategies/complex/quick_sort_utils.c \
	      strategies/medium/choose_chunk.c \
	      strategies/medium/simulate_chunk.c \
	      strategies/medium/simulate_array.c \
	      strategies/medium/simulate_search.c \
	      strategies/medium/extract_chunk.c \
	      strategies/medium/extract_search.c \
	      strategies/medium/extract_rotations.c \
	      strategies/medium/return_to_a.c \
	      strategies/medium/main_chunks.c \
	      strategies/medium/utils.c
SRCS        = main.c $(COMMON_SRCS)
BONUS_SRCS  = bonus/checker.c $(COMMON_SRCS)

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

RM          = rm -f

all: $(NAME)

bonus: $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
