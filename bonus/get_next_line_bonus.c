/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:26:06 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/11 17:21:47 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static	char	*to_save[FOPEN_MAX];
	char	*to_read;
	char	*line;
	ssize_t	count;
	
	if (fd < 0 || fd > FOPEN_MAX|| BUFFER_SIZE <= 0)
		return (NULL);
	to_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!to_read)
		return (NULL);
	count = 1;
	while (!ft_newline(to_read) && count)
	{
		count = read(fd, to_read, BUFFER_SIZE);
		if (count < 0)
			return (ft_clean_all(to_read, to_save[fd]));
		to_read[count] = '\0';
		to_save[fd] = ft_create_save(to_read, to_save[fd]);
		if (!to_save[fd])
			return (NULL);
	}
	line = ft_create_line(to_read, to_save[fd]);
	if (!line)
		return (NULL);
	to_save[fd] = ft_clean_save(to_read, to_save[fd]);
	return (line);
}

char	*ft_clean_save(char *read, char *save)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*new_save;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	len = ft_strlen(save) - i;
	new_save = ft_calloc(len, sizeof(char));
	if (!new_save)
		return (ft_clean_all(read, save));
	j = 0;
	while (save[++i])
		new_save[j++] = save[i];
	new_save[j] = '\0';
	return (new_save);	
}

char	*ft_create_line(char *read, char *save)
{
	size_t	i;
	size_t	len;
	char	*line;
		
	len = 0;
	while (save[len] && save[len] != '\n')
		len++;
	len += (save[len] == '\n');
	line = ft_calloc(len, sizeof(char));
	if (!line)
		return (ft_clean_all(read, save));
	i = 0;
	while (i < len)
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_create_save(char *read, char *save)
{
	size_t	len;
	size_t	i;
	char	*new_save;
	
	if (!*read)
		return (save);
	len = ft_strlen(read) + ft_strlen(save);
	new_save = ft_calloc(len + 1, sizeof(char));
	if (!new_save)
		return (ft_clean_all(read, save));
	i = 0;
	while (save && save[i])
	{
		new_save[i] = save[i];
		i++;
	}
	while (*read)
		new_save[i++] = *read++;
	new_save[i] = '\0';
	if (save)
		free (save);
	return (new_save); 
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t n, size_t size)
{
	char	*buf;
	size_t	len;
	size_t	i;

	len = n * size;
	buf = malloc(len);
	if(!buf)
		return (NULL);
	i = 0;
	while (i < len)
		buf[i++] = 0;
	return (buf);
}

int	ft_newline(char	*read)
{
	while (*read)
	{
		if (*read == '\n')
			return (1);
		read++;
	}
	return (0);
}

char	*ft_clean_all(char *read, char *save)
{
	if (!save)
		free(read);
	else
	{
		free(read);
		free(save);
	}
	return (NULL);
}

// #include <fcntl.h>
// int	main(int argc, char **argv)
// {
// 	int	fd;
// 	int	i;
// 	char	*line;
	
// 	if (argc < 2)
// 	{
// 		printf("You have to give a file name!");
// 		return (1);
// 	}
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("It was not possible to read the file");
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		line = get_next_line(fd);
// 	}
// }
