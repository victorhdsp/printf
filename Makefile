FILES=./src/ft_printf.o ./src/ft_printf_utils.o ./src/ft_printf_utils_bonus.o 
COMMAND_FILES=./src/commands/ft_c.o ./src/commands/ft_s.o ./src/commands/ft_digit.o ./src/commands/ft_hex.o
LIBFT=./libft/ft_calloc.o ./libft/ft_memset.o ./libft/ft_strdup.o ./libft/ft_strjoin.o ./libft/ft_memcpy.o ./libft/ft_strlen.o ./libft/ft_strchr.o ./libft/ft_toupper.o
NAME=libftprintf.a
CC=cc -Wall -Wextra -Werror -I . -g
AR=ar -rca

all: $(NAME)

$(NAME): $(FILES) $(LIBFT) $(COMMAND_FILES)
	$(AR) $(NAME) $@ $^

.o: .c
	$(CC) -c $< -o $@

bonus: all

clean: 
	rm -f $(FILES) $(LIBFT) $(COMMAND_FILES)

fclean: clean
	rm -f $(NAME)

re: clean all