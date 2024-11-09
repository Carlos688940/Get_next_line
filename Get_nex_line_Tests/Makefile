CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=10000000
NAME = teste

RM = rm -f

.PHONY: all clean re

all: ${NAME}

teste:
	${CC} ${CFLAGS} test.c ../get_next_line.c ../get_next_line_utils.c -o teste
	./teste big.txt empty.txt test.txt

clean:
	${RM} ${NAME}

re: clean all