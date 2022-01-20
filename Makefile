NAME = server
CLIENT = client
FLAGS = -Wall -Werror -Wextra
SRCSERVER = server.c
SRCCLIENT = client.c
OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)
LIBFT = libft/libft.a

all: $(NAME) $(CLIENT)

$(NAME): $(LIBFT) $(OBJSERVER)
	gcc $(FLAGS) -o $@ $^

$(CLIENT): $(LIBFT) $(OBJCLIENT)
	gcc $(FLAGS) -o $@ $^

$(LIBFT):
	make -C libft

%.o: %.c
	gcc $(FLAGS) -c $^

clean:
	rm -f $(OBJSERVER)
	rm -f $(OBJCLIENT)
	make fclean -C libft

fclean: clean
	rm -f $(NAME) $(CLIENT)

re: fclean all

.PHONY: clean fclean re