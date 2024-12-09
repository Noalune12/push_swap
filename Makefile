CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

RM = rm -f

SRCS_DIR = ./srcs

SRCS = algo_2_and_3.c algo_500.c algo_500_r_or_rr.c calculate_cost.c \
	check_args.c find_position.c min_and_max.c push_on_top.c push_swap_utils.c \
	push_swap.c rotate_and_reverse.c swap.c

SRCS_FILES = $(addprefix $(SRCS_DIR)/, $(SRCS))

OBJS = $(SRCS_FILES:.c=.o)

LIBFT_DIR = ./libft

LIBFT_A = $(LIBFT_DIR)/libft.a

LIBFT_FUNCTIONS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
	ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
	ft_striteri.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c \
	ft_strtrim.c ft_tolower.c ft_toupper.c \
	ft_printf/ft_numbers.c ft_printf/ft_words_pointer.c ft_printf/ft_printf.c

LIBFT_FILES = $(addprefix $(LIBFT_DIR)/, $(LIBFT_FUNCTIONS)) $(LIBFT_DIR)/libft.h $(LIBFT_DIR)/ft_printf/ft_printf.h $(LIBFT_DIR)/Makefile

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT_FILES)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

%.o: %.c include/push_swap.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all fclean clean re
