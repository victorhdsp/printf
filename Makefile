FILES=./src/ft_printf.o ./src/ft_printf_utils.o ./src/ft_commands_digit.o ./src/ft_commands_string.o ./src/ft_printf_utils_bonus.o ./src/ft_traitment_null.o
LIBFT=./libft/ft_calloc.o ./libft/ft_memset.o ./libft/ft_strdup.o ./libft/ft_strjoin.o ./libft/ft_memcpy.o ./libft/ft_strlen.o ./libft/ft_strchr.o
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
	rm -f $(FILES) $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: clean all