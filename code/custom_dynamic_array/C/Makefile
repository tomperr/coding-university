NAME = dyn

CC = gcc
FLAGS = -std=c89 -Wall -Werror -Wextra
INCLUDES = -Iinclude
LIBS =

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = build

vpath %.c src
vpath %.h include

SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(OBJ_DIR)/%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) $(INCLUDES) -o $(BIN_DIR)/$(NAME) $(OBJ_FILES) $(LIBS)

all: $(NAME)

clean:
	@rm -f $(OBJ_FILES)
	@echo "Objects deleted!"

fclean: clean
	@rm -f $(BIN_DIR)/$(NAME)
	@echo "Executable deleted!"

re: fclean all