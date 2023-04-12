# Compilation vars

CC		=	cc
CFLAS	=	-Wall -Werror -Wextra
RM		=	rm -f

CLIENT	=	client
SERVER	=	server
LIBFT	=	libft
NAME	=	
SRC_C	=	client.c
SRC_S	=	server.c

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER):
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_S) $(INC) -o $(SERVER)
	@echo "Server is ready.\n"

$(CLIENT):
	$(CC) $(CFLAGS) $(SRC_C) $(INC) -o $(CLIENT)
	@echo "Client is ready.\n"

clean:
	@make clean -C $(LIBFT)
	$(RM) $(CLIENT) $(SERVER)
	@echo "Client removed.\n"
	@echo "Server removed.\n"

fclean: clean
	$(RM) $(NAME)

re: fclean all

mandatory:	$(CLIENT) $(SERVER)

bonus:		mandatory

.PHONY: all clean fclean re mandatory bonus