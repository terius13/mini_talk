# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 20:37:43 by ting              #+#    #+#              #
#    Updated: 2023/12/28 14:32:22 by ting             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

SERVER = server

CLIENT = client

SERVERSRC = server.c

CLIENTSRC = client.c

SERVEROBJ = $(SERVERSRC:.c=.o)

CLIENTOBJ = $(CLIENTSRC:.c=.o)

LIBFT = ./libft/libft.a

all: $(LIBFT) $(SERVER) $(CLIENT)
	echo "SERVER & CLIENT ARE NOW READY!"

$(LIBFT):
	$(MAKE) -C libft

$(SERVER): $(SERVEROBJ) $(LIBFT)
	cc $(FLAGS) $(SERVEROBJ) $(LIBFT) -o $(SERVER)

$(CLIENT): $(CLIENTOBJ) $(LIBFT)
	cc $(FLAGS) $(CLIENTOBJ) $(LIBFT) -o $(CLIENT)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(SERVEROBJ) $(CLIENTOBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(SERVER) $(CLIENT)
	echo "SERVER & CLIENT HAVE BEEN CLEANED SUCCESSFULLY


re: fclean all

