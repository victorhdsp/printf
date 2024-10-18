FILES=./src/ft_printf.o ./src/ft_printf_utils.o ./src/ft_commands.o
BONUS=
NAME=libftprintf.a
CC=cc -Wall -Wextra -Werror -g -I .
AR=ar -rca

all: $(NAME)

$(NAME): $(FILES) $(LIBFT)
	$(AR) $(NAME) $@ $^

.o: .c
	$(CC) -c $< -o $@

clean: 
	rm -f $(FILES)

fclean: clean
	rm -f $(NAME)

re: clean all