#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "../get_next_line.h"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int	main(int argc, char **argv)
{
	int	fd;
	int	i;
	int	j;
	int	k;
	char	*line;

	if (argc < 2)
	{
		printf ("Error!\nYou have to give a file name to read the content!");
		return (1);
	}
	j = 1;
	k = 1;
	while (j < argc)
	{
		fd = open(argv[k], O_RDONLY);
		if (fd < 0)
		{
			printf ("Error! It was not possible to open file!");
			return (1);
		}
		if (strcmp(argv[k],"big.txt") == 0)
			printf(RED"Big file!!\n\n"RESET);
		else if (strcmp(argv[k],"empty.txt") == 0)
			printf(RED"Empty file!!\n\n"RESET);
		else if (strcmp(argv[k],"multiple_line_with_nl.txt") == 0)
			printf(RED"multiple_line_with_nl file!!\n\n"RESET);
		else if (strcmp(argv[k],"multiple_nlx5.txt") == 0)
			printf(RED"multiple_nlx5 file!!\n\n"RESET);
		else if (strcmp(argv[k],"alternate_line_nl_no_nl.txt") == 0)
			printf(RED"alternate_line_nl_no_nl file!!\n\n"RESET);
		else if (strcmp(argv[k],"41_with_nl.txt") == 0)
			printf(RED"41_with_nl file!!\n\n"RESET);
		else if (strcmp(argv[k],"42_no_nl.txt") == 0)
			printf(RED"42_no_nl file!!\n\n"RESET);
		line = get_next_line(fd);
		i = 1;
		while (line)
		{
			printf(GREEN"Line %d:"RESET"%s\n", i, line);
			free(line);
			i++;
			line = get_next_line(fd);
		}
		j++;
		k++;
		printf(GREEN"Line %d:"RESET"%s", i, line);
		printf("\n\n\n\n");
	}
	return (0);
}