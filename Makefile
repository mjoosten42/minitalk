NAME = server
CLIENT = client
FLAGS = -Wall -Werror -Wextra
SRCSERVER = server.c
SRCCLIENT = client.c
OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)
LIBFT = libft/libft.a

all: $(NAME) $(CLIENT)

$(NAME): $(OBJSERVER) $(LIBFT)
	gcc $(FLAGS) -o $@ $^

$(CLIENT): $(OBJCLIENT) $(LIBFT)
	gcc $(FLAGS) -o $@ $^

$(LIBFT):
	make -C libft

%.o: %.c
	gcc $(FLAGS) -c $^

clean:
	rm -f $(OBJ)
	make fclean -C libft

fclean: clean
	rm -f $(NAME) $(CLIENT)

re: fclean all

.PHONY: clean fclean re