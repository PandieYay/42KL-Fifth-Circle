NAME = ./a.out
SRCS = ./test.cpp
INC = ./vector.hpp
FLAGS = -Wall -Wextra -Werror -std=c++11

all: $(NAME)

$(NAME): ${SRCS} ${INC}
	c++ ${FLAGS} -o ${NAME} ${SRCS}

clean:
	rm -f ${NAME}

fclean: clean

re: fclean all

.PHONY: all clean fclean re