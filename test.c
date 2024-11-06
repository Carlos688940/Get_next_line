#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char	n[100];
	int	fd;
	int	x;
	(void)n;

	fd = open("test.txt", O_RDWR);
	x = read(fd, n, 3);
	while (x)
	{
		n[x] = '\0';
		printf("buf -> %s\n", n);
		x = read(fd, n, 3);
	}
}