# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 20:37:43 by ting              #+#    #+#              #
#    Updated: 2023/12/31 18:47:56 by ting             ###   ########.fr        #
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

SERVERBONUS = server_bonus

CLIENTBONUS = client_bonus

SERVERBONUS_SRC = server_bonus.c

CLIENTBONUS_SRC = client_bonus.c

SERVERBONUS_OBJ = $(SERVERBONUS_SRC:.c=.o)

CLIENTBONUS_OBJ = $(CLIENTBONUS_SRC:.c=.o)

LIBFT = ./libft/libft.a

all: $(LIBFT) $(SERVER) $(CLIENT)
	@echo "$(COLOUR_CYAN)SERVER & CLIENT ARE NOW READY!$(COLOUR_END)"

$(LIBFT):
	@$(MAKE) -C libft

$(SERVER): $(SERVEROBJ) $(LIBFT)
	@cc $(FLAGS) $(SERVEROBJ) $(LIBFT) -o $(SERVER)

$(CLIENT): $(CLIENTOBJ) $(LIBFT)
	@cc $(FLAGS) $(CLIENTOBJ) $(LIBFT) -o $(CLIENT)

bonus: $(LIBFT) $(SERVERBONUS) $(CLIENTBONUS)
	@echo "$(COLOUR_MAGENTA)BONUS SERVER & CLIENT ARE NOW READY!$(COLOUR_END)"	

$(SERVERBONUS): $(SERVERBONUS_OBJ) $(LIBFT)
	@cc $(FLAGS) $(SERVERBONUS_OBJ) $(LIBFT) -o $(SERVERBONUS)

$(CLIENTBONUS): $(CLIENTBONUS_OBJ) $(LIBFT)
	@cc $(FLAGS) $(CLIENTBONUS_OBJ) $(LIBFT) -o $(CLIENTBONUS)

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(SERVEROBJ) $(CLIENTOBJ)
	@rm -rf $(SERVERBONUS_OBJ) $(CLIENTBONUS_OBJ)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(SERVER) $(CLIENT)
	@rm -rf $(SERVERBONUS) $(CLIENTBONUS)
	@echo "$(COLOUR_GREEN)SERVER & CLIENT HAVE BEEN CLEANED SUCCESSFULLY$(COLOUR_END)"


re: fclean all

