NAME = server
CLIENT = client
FLAGS = -Wall -Werror -Wextra

all: $(NAME) $(CLIENT)

$(NAME): $(NAME).o
	gcc $(FLAGS) -o $@ $^

$(CLIENT): $(CLIENT).o
	gcc $(FLAGS) -o $@ $^

%.o: %.c
	gcc $(FLAGS) -c $^

clean:
	rm -f $(NAME).o $(CLIENT).o

fclean: clean
	rm -f $(NAME) $(CLIENT)

re: fclean all

.PHONY: clean fclean re