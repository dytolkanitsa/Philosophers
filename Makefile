NAME = philo

HEADER = philo.h

SRC = philo.c threads.c parser.c utils.c utils2.c

FLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

all : ${NAME}

%.o : %.c $(HEADER)
	gcc ${FLAGS} -c $< -o $@

${NAME} : ${SRC} ${OBJ}
	gcc ${FLAGS} -o ${NAME} ${SRC}

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re