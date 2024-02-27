NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = source_files/main.c \
	  source_files/operations.c \
	  source_files/pull.c \
	  source_files/sorting.c \
	  source_files/utils.c \
	  source_files/utils2.c \
	  source_files/utils3.c \
	  source_files/free_error.c \
	  source_files/index.c \
	  source_files/operations2.c \
	  source_files/radix.c

OBJ = $(SRC:.c=.o)

all: ${NAME}

${NAME}: $(OBJ)
		$(CC) $(CFLAGS) -lm $(SRC) -o $(NAME)
		@echo "./push_swap created!"

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re