
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a


CLIENT_SRC = client.c
SERVER_SRC = server.c

CLIENT_EXECUTABLE = client
SERVER_EXECUTABLE = server

NAME = $(CLIENT_EXECUTABLE) $(SERVER_EXECUTABLE)
all: $(NAME)

$(SERVER_EXECUTABLE): $(SERVER_SRC) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER_EXECUTABLE) $(SERVER_SRC) $(LIBFT)

$(CLIENT_EXECUTABLE): $(CLIENT_SRC) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT_EXECUTABLE) $(CLIENT_SRC) $(LIBFT)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
