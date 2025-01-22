CC = cc
CFLAGS =  -g -Wall -Wextra -Werror -D BUFFER_SIZE=500
AR = ar rcs
NAME = get_next_line.a
RM = rm -f

FILES_C = get_next_line.c get_next_line_utils.c get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = $(FILES_C:.c=.o)

.PHONY: all rm re run

all: ${NAME}

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	${RM} ${OBJS} ${OBJS_BON}

fclean: clean
	${RM} ${NAME}

re: fclean all
