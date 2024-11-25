# find . -type f -name "*.o" -exec rm -f {} +

NAME := minitalk
.DEFAULT_GOAL := all
CC := cc
RM := rm -rf

################################################################################
###############                  DIRECTORIES                      ##############
################################################################################

OBJ_DIR := _obj
LIBFT_PATH := libft
LIBFT := $(LIBFT_PATH)/libft.a
# PRINTF_PATH := ft_printf
# PRINTF := $(PRINTF_PATH)/ft_printf
INC_DIRS := Includes $(LIBFT)
SRC_DIRS := src

vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

################################################################################
###############                  SOURCE FILES                     ##############
################################################################################

CLIENT_SRC := client.c
SERVER_SC := server.c

SRC := $(addprefix src/, $(CLIENT_SRC), src/ $(SERVER_SRC))

################################################################################
###############               OBJECT FILES & RULES                ##############
################################################################################

OBJS := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# Compilation flags and linking options
CFLAGS := -Wall -Wextra -Werror -g -IIncludes -Ilibft $(addprefix -I, $(INC_DIRS))
LDFLAGS := -Llibft -Lft_printf
CFLAGS_SAN := $(CFLAGS) -fsanitize=address -g
LDFLAGS_SAN := $(LDFLAGS) -fsanitize=address

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Default target to build
all: $(NAME)

# Build push_swap with libft and object files
$(NAME): $(LIBFT) $(OBJS)
# $(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -lftprintf -o $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -L./libft -L./ft_printf -lftprintf -o $(NAME)
	@echo "\033[0;32mSuccessful Compilation of $(NAME)\033[0m"

bonus:

# Compile source files into object files
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the object directory if not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up object files and libft
clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_PATH)

# Clean up everything (object files and binaries)
fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)

# Rebuild everything (clean + all)
re: fclean all

# Build with sanitizers
san: fclean
	$(MAKE) C

-include $(OBJS:%.o=%.d)

.PHONY: all clean fclean re bonus san