NAME	= philo
CC		= clang
#FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -I.
SRC		= src/main.c \
		src/parser.c \
		src/getms.c \
		src/error.c
OBJ		= $(SRC:%.c=%.o)

.o: .c
	$(CC) $(CFLAGS) $? -o $@

.PHONY: all re clean fclean norm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRC)
	norminette philo.h