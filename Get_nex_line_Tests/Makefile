CC = cc
CFLAGS = -g -Wall -Wextra -Werror -D BUFFER_SIZE=5
NAME = teste

RM = rm -f

.PHONY: all clean re

all: ${NAME}

teste:
	${CC} ${CFLAGS} test.c ../get_next_line.c ../get_next_line_utils.c -o teste
##----------- No mac -------------------
#leaks --atExit -- ./teste empty.txt test.txt big.txt 
##----------- na escola ----------------
	valgrind --leak-check=full ./teste multiple_nlx5.txt 
#big.txt empty.txt test.txt
clean:
	${RM} ${NAME}

re: clean all
