NAME = linked_list

CC = g++
FLAGS = -std=c++98 -Wall -Werror -Wextra
INCLUDES = -Iinclude
LIBS =

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = build

vpath %.cpp src
vpath %.hpp include

SRC_FILES=$(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(OBJ_DIR)/%.o: %.cpp
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
