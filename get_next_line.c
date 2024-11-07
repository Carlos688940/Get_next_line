/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:48 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/07 23:26:03 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_create_line(char *save, char *read)
{
	size_t	len;
	char	*line;
	char	*line_start;

	len = 0;
	while (save[len] && save[len] != '\n')
		len++;
	len += (save[len] == '\n');
	line = ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (ft_clean_all(read, save));
	line_start = line;
	while (*save && *save != '\n')
		*line++ = *save++;
	if (*save == '\n')
		*line++ = *save;
	*line = '\0';
	return (line_start);
}

char	*ft_addchars(char *read_buf, char *save_buf)
{
	char	*ptr;
	char	*ptr_start;
	char	*save_start;
	size_t	len;

	if (!save_buf)
	{
		save_buf = ft_calloc(1, sizeof(char));
		if (!save_buf)
			return (NULL);
	}
	save_start = save_buf;
	len = ft_strlen(read_buf) + ft_strlen(save_buf);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (ft_clean_all(read_buf, save_buf));
	ptr_start = ptr;
	while (*save_buf)
		*ptr++ = *save_buf++;
	while (*read_buf)
		*ptr++ = *read_buf++;
	*ptr = '\0';
	free(save_start);
	return (ptr_start);
}

char	*ft_check(int fd)
{
	char	*read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read)
		return (NULL);
	else
		return (read);
}

char	*get_next_line(int fd)
{
	char		*to_read;
	char		*line;
	static char	*to_save;
	ssize_t		n_bytes;

	to_read = ft_check(fd);
	if (!to_read)
		return (NULL);
	n_bytes = 1;
	while (!(ft_newline(to_read)) && n_bytes)
	{
		n_bytes = read(fd, to_read, BUFFER_SIZE);
		if (n_bytes < 0)
			return (ft_clean_all(to_read, to_save));
		to_read[n_bytes] = '\0';
		to_save = ft_addchars(to_read, to_save);
		if (!to_save)
			return (NULL);
	}
	line = ft_create_line(to_save, to_read);
	if (!line)
		return (NULL);
	to_save = ft_clean_save(to_save, to_read);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int fd);

int main()
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
// #include <fcntl.h>
// #include <stdlib.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int	fd;
// 	char	*s;

// 	fd = 1;
// 	fd = open("test.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// }
