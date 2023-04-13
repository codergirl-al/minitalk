# Compilation vars

CC		=	cc
CFLAS	=	-Wall -Werror -Wextra
RM		=	rm -f

CLIENT	=	client
SERVER	=	server
LIBFT	=	libft
LIBFT_N	=	libft.a

NAME	=	
SRC_C	=	client.c utils.c
SRC_S	=	server.c utils.c

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER):
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_S) $(INC) -L$(LIBFT) -lft -o $(SERVER)
	@echo "Server is ready."

$(CLIENT):
	$(CC) $(CFLAGS) $(SRC_C) $(INC) -o $(CLIENT)
	@echo "Client is ready.\n"

clean:
	@make clean -C $(LIBFT)
	$(RM) $(CLIENT) $(SERVER)
	@echo "Client removed."
	@echo "Server removed."

fclean: clean
	$(RM) $(LIBFT)/$(LIBFT_N)
	$(RM) $(NAME)

re: fclean all

mandatory:	$(CLIENT) $(SERVER)

bonus:		mandatory

.PHONY: all clean fclean re mandatory bonus
