NAME	= philo
CC		= clang
#FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -Iphilo/
PATH	= philo/src
SRC		= $(PATH)/main.c \
		$(PATH)/parser.c \
		$(PATH)/philo.c \
		$(PATH)/init.c \
		$(PATH)/utils.c
OBJ		= $(SRC:.c=.o)

.PHONY: all clean fclean re norm

%.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o philo/$@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f philo/$(NAME)

re: fclean all

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC) philo/philo.h