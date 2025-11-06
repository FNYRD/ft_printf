NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror -I./includes/ -I./libft

CC = cc

AR = ar rcs

RM = rm -f

SRCS =	srcs/ft_printf.c \
		srcs/ft_hexa.c \
		srcs/ft_hexa_void.c \
		srcs/ft_putchar.c \
		srcs/ft_putstr.c \
		srcs/ft_dotcase_bonus.c \
		srcs/ft_putminzero_bonus.c \
		srcs/ft_count_0xchar_bonus.c \

all: $(NAME)

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all

.SILENT: