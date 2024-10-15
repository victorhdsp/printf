FILES=main.o ./src/unity.o
TESTS=./tests/test_reader.o
NAME=test.out
ROOT=..
PRINTF=$(ROOT)/libftprintf.a
LIBFT=$(ROOT)/libft.a
CC=clang -Wall -Wextra -Werror -g -I $(ROOT)/headers/ -I $(ROOT)/libft/ -I ./src/

all: $(FILES) $(TESTS) $(PRINTF)
	$(CC) -o $(NAME) $(FILES) $(TESTS) libftprintf.a libft.a

$(PRINTF):
	make -C $(ROOT) && mv $(PRINTF) . && mv $(LIBFT) .

.o: .c
	$(CC) -c $< -o $@

clean:
	rm -f $(FILES) $(TESTS) && make -C $(ROOT) clean

fclean: clean
	rm -f $(NAME) $(TESTS) libftprintf.a libft.a && make -C $(ROOT) fclean