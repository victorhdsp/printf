HEADER=./headers/
FILES=./src/ft_printf.o ./src/ft_reader.o
BONUS=
LIBFT=libft.a
NAME=libftprintf.a
CC=cc -Wall -Wextra -Werror -g -I ./headers/ -I ./libft/
AR=ar -rca

all: $(NAME)

$(NAME): $(FILES) $(LIBFT)
	$(AR) $(NAME) $@ $^

.o: .c
	$(CC) -I $(HEADER) -c $< -o $@

$(LIBFT):
	make -C libft && mv libft/libft.a .

clean: 
	rm -f $(FILES)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: clean all