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
	@$(AR) $(NAME) $(OBJS)

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS} ${OBJS_BON}

fclean: clean
	${RM} ${NAME}

re: fclean all

##Colors
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m
