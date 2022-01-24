NAME = $(SERVER) $(CLIENT)
SERVER = server
CLIENT = client
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(SERVER): $(SERVER).o
	gcc $(FLAGS) -o $@ $^

$(CLIENT): $(CLIENT).o
	gcc $(FLAGS) -o $@ $^

%.o: %.c
	gcc $(FLAGS) -c $^

clean:
	rm -f $(SERVER).o $(CLIENT).o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re