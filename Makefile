CFLAGS = -Werror -Wextra -Wall

SRC = ft_printf.c len_putchar.c len_putstr.c len_putnbr.c len_putnbr_unsigned.c len_putnbr_hexa.c len_putptr.c

OBJ = $(SRC:.c=.o)

RM = rm -f

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -r $(NAME) $(OBJ)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) a.out

re: fclean all

.PHONY: all clean fclean re
