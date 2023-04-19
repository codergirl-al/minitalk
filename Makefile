# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 22:24:19 by apeposhi          #+#    #+#              #
#    Updated: 2023/04/19 12:50:34 by apeposhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
	cd libft && make
	$(CC) $(CFLAGS) libft/libft.a $(SRC_S) $(INC) -o $(SERVER)
	@echo "Server is ready."

$(CLIENT):
	cd libft && make
	$(CC) $(CFLAGS) libft/libft.a $(SRC_C) $(INC) -o $(CLIENT)
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
