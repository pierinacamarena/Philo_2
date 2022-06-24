NAME = philo
CC = gcc -g
FLAGS = -Wall -Werror -Wextra
THREADS = -pthread
HEADER = includes
SRC = src
OBJ = objects
SOURCES =	main.c \
			error.c \
			parsing.c \
			time.c \
			utils.c \
			philo.c \
			activities.c \
			checker.c

SRCS = $(addprefix $(SRC)/, $(SOURCES))
OBJS = $(addprefix $(OBJ)/, $(SOURCES:.c=.o))

all: $(OBJ) $(NAME)

$(OBJ):
	mkdir -p $(OBJ)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(THREADS) -o $(NAME) $(OBJS) -g

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(FLAGS) $(THREADS) -o $@ -c $^ -I$(HEADER)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
