CC = cc
CFLAGS = -g -Wall -Wextra -Werror -D BUFFER_SIZE=5
NAME = teste

RM = rm -f

# Lista de arquivos de teste
TEST_FILES = big.txt empty.txt multiple_line_with_nl.txt multiple_nlx5.txt \
             alternate_line_nl_no_nl.txt 41_with_nl.txt 42_no_nl.txt

.PHONY: all clean re run_tests

all: ${NAME}

${NAME}:
	${CC} ${CFLAGS} test.c ../get_next_line.c ../get_next_line_utils.c -o ${NAME}

# Alvo para rodar com Valgrind em cada arquivo
run_tests: ${NAME}
	@for file in ${TEST_FILES}; do \
		echo "Running Valgrind on $$file"; \
		valgrind --leak-check=full ./teste $$file; \
	done

# Alvo para rodar com leaks no macOS
run_tests_mac: ${NAME}
	@for file in ${TEST_FILES}; do \
		echo "Running leaks on $$file"; \
		leaks --atExit -- ./teste $$file; \
	done

clean:
	${RM} ${NAME}

re: clean all






# CC = cc
# CFLAGS = -g -Wall -Wextra -Werror -D BUFFER_SIZE=5
# NAME = teste

# RM = rm -f

# .PHONY: all clean re

# all: ${NAME}

# teste:
# 	${CC} ${CFLAGS} test.c ../get_next_line.c ../get_next_line_utils.c -o teste
# ##----------- No mac -------------------
							
# 	leaks --atExit -- ./teste alternate_line_nl_no_nl.txt big.txt empty.txt multiple_line_with_nl.txt multiple_nlx5.txt
# ##----------- na escola ----------------
# #valgrind --leak-check=full ./teste multiple_nlx5.txt 
# clean:
# 	${RM} ${NAME}

# re: clean all
