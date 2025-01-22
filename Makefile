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
	@echo "$(GREEN) GNL library created!$(RESET)"

clean:
	${RM} ${OBJS} ${OBJS_BON}
	@echo "$(GREEN)GNL objects cleaned!$(RESET)"

fclean: clean
	${RM} ${NAME}
	@echo "$(GREEN)Everything gnl cleaned!$(RESET)"

re: fclean all

##Colors
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m
