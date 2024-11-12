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

	// if (argc < 4)
	// {
	// 	printf ("Error!\nYou have to give a file name to read the content!");
	// 	return (1);
	// }
	j = 1;
	k = 1;
	while (j < argc)
	{
		fd = open(argv[k], O_RDONLY);
		if (fd < 0)
		{
			printf ("Error! I was not possible to open the file!");
			return (1);
		}
		if (strcmp(argv[k],"empty.txt") == 0)
			printf(RED"Empty file!!\n\n"RESET);
		else if (strcmp(argv[k],"big.txt") == 0)
			printf(RED"Big file!!\n\n"RESET);
		else if (strcmp(argv[k],"test.txt") == 0)
			printf(RED"Test file!!\n\n"RESET);
		line = get_next_line(fd);
		i = 1;
		while (line)
		{
			printf(GREEN"Line %d:"RESET"%s", i, line);
			free(line);
			i++;
			line = get_next_line(fd);
		}
		j++;
		k++;
		printf("\n\n\n\n");
	}
	return (0);
}