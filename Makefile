
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a


CLIENT_SRC = client.c
SERVER_SRC = server.c

CLIENT_BONUS_SRC = client_bonus.c
SERVER_BONUS_SRC = server_bonus.c



CLIENT_EXECUTABLE = client
SERVER_EXECUTABLE = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

NAME = $(CLIENT_EXECUTABLE) $(SERVER_EXECUTABLE)
BONUS_NAME = $(CLIENT_BONUS) $(SERVER_BONUS)

all: $(NAME)

$(SERVER_EXECUTABLE): $(SERVER_SRC) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER_EXECUTABLE) $(SERVER_SRC) $(LIBFT)

$(CLIENT_EXECUTABLE): $(CLIENT_SRC) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT_EXECUTABLE) $(CLIENT_SRC) $(LIBFT)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

bonus : $(BONUS_NAME)

$(SERVER_BONUS): $(SERVER_BONUS_SRC) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_BONUS_SRC) $(LIBFT)

$(CLIENT_BONUS): $(CLIENT_BONUS_SRC) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_BONUS_SRC) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	$(RM) $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
