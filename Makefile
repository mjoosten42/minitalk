NAME = server
CLIENT = client
FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

all: $(NAME) $(CLIENT)

$(NAME): $(LIBFT) $(NAME).o
	gcc $(FLAGS) -o $@ $^

$(CLIENT): $(LIBFT) $(CLIENT).o
	gcc $(FLAGS) -o $@ $^

$(LIBFT):
	make -C libft

%.o: %.c
	gcc $(FLAGS) -c $^

clean:
	rm -f $(NAME).o $(CLIENT).o
	make fclean -C libft

fclean: clean
	rm -f $(NAME) $(CLIENT)

re: fclean all

.PHONY: clean fclean re