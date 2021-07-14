NAME	= philo
NAMEB	= philo_bonus
SRC_P	= philo/src
SRC_PB	= philo_bonus/src
SRC		= $(SRC_P)/main.c \
		$(SRC_P)/time.c \
		$(SRC_P)/parser.c \
		$(SRC_P)/createphilo.c
SRCB	= $(SRC_PB)/main.c \
		$(SRC_PB)/time.c
OBJ		= $(SRC:%.c=%.o)
OBJB	= $(SRCB:%.c=%.o)
CC		= gcc
#FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -Iphilo -Iphilo_bonus

.PHONY: all re clean fclean norm

.o: .c
	$(CC) $(CFLAGS) $< -o $@

all: $(NAME) $(NAMEB)

$(NAME): $(OBJ)	philo/philo.h
	$(CC) $(OBJ) -o philo/$@

$(NAMEB): $(OBJB) philo_bonus/philo_bonus.h
	$(CC) $(OBJB) -o philo_bonus/$@

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f philo/$(NAME) philo_bonus/$(NAMEB)

re: fclean all

norm:
	norminette $(SRC) philo/philo.h