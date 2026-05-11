# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jingywu <jingywu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/06 11:41:29 by jingywu           #+#    #+#              #
#    Updated: 2026/03/09 23:05:05 by jingywu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SERVER = server
CLIENT = client
BSERVER = serverbonus
BCLIENT = clientbonus

CFLAGS = -Wall -Wextra -Werror -I libft -I ft_printf
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
FTPRINTF_DIR = ft_printf
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a

SERVER_SRC = server.c
CLIENT_SRC = client.c
BSERVER_SRC = server_bonus.c
BCLIENT_SRC = client_bonus.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
BSERVER_OBJ = $(BSERVER_SRC:.c=.o)
BCLIENT_OBJ = $(BCLIENT_SRC:.c=.o)

all:$(SERVER) $(CLIENT)
bonus: $(BSERVER) $(BCLIENT)

$(LIBFT):
	make -C $(LIBFT_DIR)
$(FTPRINTF):
	make -C $(FTPRINTF_DIR)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT) $(FTPRINTF)
	cc $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) $(FTPRINTF) -o $(CLIENT)
$(SERVER): $(SERVER_OBJ) $(LIBFT) $(FTPRINTF)
	cc $(CFLAGS) $(SERVER_OBJ) $(LIBFT) $(FTPRINTF) -o $(SERVER)
$(BCLIENT): $(BCLIENT_OBJ) $(LIBFT) $(FTPRINTF)
	cc $(CFLAGS) $(BCLIENT_OBJ) $(LIBFT) $(FTPRINTF) -o $(BCLIENT)
$(BSERVER): $(BSERVER_OBJ) $(LIBFT) $(FTPRINTF)
	cc $(CFLAGS) $(BSERVER_OBJ) $(LIBFT) $(FTPRINTF) -o $(BSERVER)

%.o: %.c
	cc ${CFLAGS} -c $< -o $@
clean:
	make -C $(LIBFT_DIR) clean
	make -C $(FTPRINTF_DIR) clean
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)
	rm -f $(BSERVER_OBJ) $(BCLIENT_OBJ)
fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(FTPRINTF_DIR) fclean
	rm -f $(SERVER) $(CLIENT)
	rm -f $(BSERVER) $(BCLIENT)
re: fclean all
.PHONY: all clean fclean re