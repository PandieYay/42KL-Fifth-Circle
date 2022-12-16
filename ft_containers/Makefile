NAME = ./a.out
SRCS = ./test.cpp
INC = ./vector.hpp ./functions.hpp ./iterators.hpp ./reverse_iterator.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): ${SRCS} ${INC}
	c++ ${FLAGS} -o ${NAME} ${SRCS}

iterators: ./iteratorstester.cpp ${INC}
	c++ ${FLAGS} -o ${NAME} ./iteratorstester.cpp

clean:
	rm -f ${NAME}

fclean: clean

re: fclean all

.PHONY: all clean fclean re iterators