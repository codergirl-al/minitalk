# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 22:24:19 by apeposhi          #+#    #+#              #
#    Updated: 2023/04/20 17:39:51 by apeposhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation vars

CC		=	cc
CFLAS	=	-Wall -Werror -Wextra
RM		=	rm -f

CLIENT	=	client
SERVER	=	server

NAME	=	
SRC_C	=	client.c utils.c
SRC_S	=	server.c utils.c

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER):
	$(CC) $(CFLAGS) $(SRC_S) $(INC) -o $(SERVER)
	@echo "Server is ready."

$(CLIENT):
	$(CC) $(CFLAGS) $(SRC_C) $(INC) -o $(CLIENT)
	@echo "Client is ready.\n"

clean:
	$(RM) $(CLIENT) $(SERVER)
	@echo "Client removed."
	@echo "Server removed."

fclean: clean
	$(RM) $(NAME)

re: fclean all

mandatory:	$(CLIENT) $(SERVER)

bonus:		mandatory

.PHONY: all clean fclean re mandatory bonus
