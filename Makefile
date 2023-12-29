# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 20:37:43 by ting              #+#    #+#              #
#    Updated: 2023/12/29 13:11:08 by ting             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

COLOUR_GREEN=\033[0;32m

COLOUR_CYAN = \033[0;36m

COLOUR_MAGENTA = \033[0;35m

COLOUR_END=\033[0m

SERVER = server

CLIENT = client

SERVERSRC = server.c

CLIENTSRC = client.c

SERVEROBJ = $(SERVERSRC:.c=.o)

CLIENTOBJ = $(CLIENTSRC:.c=.o)

LIBFT = ./libft/libft.a

all: $(LIBFT) $(SERVER) $(CLIENT)
	@echo "$(COLOUR_CYAN)SERVER & CLIENT ARE NOW READY!$(COLOUR_END)"

$(LIBFT):
	@$(MAKE) -C libft

$(SERVER): $(SERVEROBJ) $(LIBFT)
	@cc $(FLAGS) $(SERVEROBJ) $(LIBFT) -o $(SERVER)

$(CLIENT): $(CLIENTOBJ) $(LIBFT)
	@cc $(FLAGS) $(CLIENTOBJ) $(LIBFT) -o $(CLIENT)

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(SERVEROBJ) $(CLIENTOBJ)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(SERVER) $(CLIENT)
	@echo "$(COLOUR_GREEN)SERVER & CLIENT HAVE BEEN CLEANED SUCCESSFULLY$(COLOUR_END)"


re: fclean all

