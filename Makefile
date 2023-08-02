NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CSFLAGS = #-I/Users/asaber/.brew/opt/readline/include
LDFLAGS =# -L/Users/asaber/.brew/opt/readline/lib

LIBFT_DIR = __LIBFT/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIRS = execution parsing __ENV __LIBFT
MAIN_SRC_DIR = .

OBJ_DIR = obj
MAIN_OBJ_DIR = obj/main

SRC = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
MAIN_SRC = $(wildcard $(MAIN_SRC_DIR)/*.c)

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
MAIN_OBJ = $(addprefix $(MAIN_OBJ_DIR)/,$(MAIN_SRC:.c=.o))

$(shell mkdir -p $(OBJ_DIR) $(addprefix $(OBJ_DIR)/,$(SRC_DIRS)) $(MAIN_OBJ_DIR))

RM = rm -rf

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(CSFLAGS) -c $< -o $@

$(MAIN_OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(CSFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(MAIN_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ) $(MAIN_OBJ) -lreadline -L$(LIBFT_DIR) -lft

clean:
	$(RM) $(OBJ) $(MAIN_OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
