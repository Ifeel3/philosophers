NAME	= philo
#FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -Iphilo/src
PATH	= philo/src
SRC		= $(PATH)/main.c \
		$(PATH)/ft_atoi.c \
		$(PATH)/utils.c \
		$(PATH)/parser.c \
		$(PATH)/init.c \
		$(PATH)/philo.c \
		$(PATH)/monitor.c \
		$(PATH)/getms.c
OBJ		= $(SRC:%.c=%.o)
CC		= clang

.o: .c
	$(CC) $(CLFAGS) -c $? -o $@

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o philo/$@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f philo/$(NAME)

re: fclean $(NAME)

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC) philo/src/philo.h
