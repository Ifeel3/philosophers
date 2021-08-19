NAME	= philo
CC		= clang
#FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -Iphilo/
PATH	= philo/src
SRC		= $(PATH)/main.c \
		$(PATH)/parser.c \
		$(PATH)/philo.c \
		$(PATH)/init.c
OBJ		= $(SRC:.c=.o)

.PHONY: all clean fclean re norm

%.o: %.c
	@$(CC) $(CFLAGS) -c $? -o $@
	@echo "creating object file $@"

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o philo/$@
	@echo "creating philo binary file"

clean:
	@rm -f $(OBJ)
	@echo "clean object files"

fclean: clean
	@rm -f philo/$(NAME)
	@echo "clean binary file"

re: fclean all

norm:
	@norminette $(SRC) philo/philo.h