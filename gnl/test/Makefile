#Compiler variables

CC= gcc
CC_FLAGS= -Wall -Wextra -Werror

#General variables

LIB_DIR= ../libft/
LIB_NAME= ft
HEADERS= ../libft/includes/
SRCS_DIR= ../
SRC_NAME= $(SRCS_DIR)get_next_line.c
MAIN_NAME= main.c
OBJ_NAME= get_next_line.o
NAME= get_next_line

# Debug variables

CC_DEBUG_FLAGS= -g -o0
OBJ_DBG_NAME= get_next_line_dg.o
DBG_NAME= get_next_line_dg

#Release set

all: $(NAME)

$(NAME): $(OBJ_NAME)
	$(CC) $(CC_FLAGS) -I../ -I$(HEADERS) -L$(LIB_DIR) -l$(LIB_NAME) $(MAIN_NAME) $< -o $@

$(OBJ_NAME): $(SRC_NAME)
	$(CC) $(CC_FLAGS) -I$(HEADERS) -c $< -o $@

#Debug set

debug: $(DBG_NAME)

$(DBG_NAME): $(OBJ_DBG_NAME)
	$(CC) $(CC_FLAGS) $(CC_DEBUG_FLAGS) -I../ -I$(HEADERS) -L$(LIB_DIR) -l$(LIB_NAME) $(MAIN_NAME) $< -o $@

$(OBJ_DBG_NAME): $(SRC_NAME)
	$(CC) $(CC_FLAGS) $(CC_DEBUG_FLAGS) -I$(HEADERS) -c $< -o $@

clean:
	rm *.o

fclean: clean
	rm $(NAME)
	rm $(DBG_NAME)

re: fclean all