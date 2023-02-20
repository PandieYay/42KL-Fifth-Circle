NAME = ./a.out
SRCS = ./test.cpp
INC = ./vector.hpp ./functions.hpp ./iterators.hpp ./reverse_iterator.hpp ./stack.hpp ./map.hpp ./redblacktree.hpp
TESTERRDIR = ./testers
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): ${SRCS} ${INC}
	c++ ${FLAGS} -o ${NAME} ${SRCS}

iterators: ${TESTERRDIR}/iteratorstester.cpp ${INC}
	c++ ${FLAGS} -o ${NAME} ${TESTERRDIR}/iteratorstester.cpp

capacity: ${TESTERRDIR}/capacitytester.cpp ${INC}
	c++ ${FLAGS} -o ${NAME} ${TESTERRDIR}/capacitytester.cpp

modifier: ${TESTERRDIR}/modifiertester.cpp ${INC}
	c++ ${FLAGS} -o ${NAME} ${TESTERRDIR}/modifiertester.cpp

stack: ${TESTERRDIR}/stacktester.cpp ${INC}
	c++ ${FLAGS} -o ${NAME} ${TESTERRDIR}/stacktester.cpp

pair: ${TESTERRDIR}/pairtester.cpp ${INC}
	c++ ${FLAGS} -o ${NAME} ${TESTERRDIR}/pairtester.cpp

map: ${TESTERRDIR}/maptester.cpp ${INC}
	c++ ${FLAGS} -o ${NAME} ${TESTERRDIR}/maptester.cpp

mapleak: ${TESTERRDIR}/maptester.cpp ${INC}
	c++ ${FLAGS} -o ${NAME} ${TESTERRDIR}/mapleaktester.cpp

clean:
	rm -f ${NAME}

fclean: clean

re: fclean all

.PHONY: all clean fclean re iterators