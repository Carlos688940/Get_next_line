/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:26:06 by carlaugu          #+#    #+#             */
/*   Updated: 2025/01/22 11:45:29 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*to_save[FOPEN_MAX];
	char		*to_read;
	char		*line;
	int			count;

	to_read = ft_first_check(fd);
	if (!to_read)
		return (NULL);
	count = 1;
	while (!(ft_newline(to_read)) && count)
	{
		count = read(fd, to_read, BUFFER_SIZE);
		if (count < 0)
			return (ft_clean_all(&to_read, &to_save[fd]));
		to_read[count] = '\0';
		to_save[fd] = ft_create_save(to_read, to_save[fd]);
		if (!to_save[fd])
			return (ft_clean_all(&to_read, &to_save[fd]));
	}
	line = ft_create_line(to_save[fd]);
	if (!line)
		return (ft_clean_all(&to_read, &to_save[fd]));
	to_save[fd] = ft_clean_save(to_save[fd]);
	free (to_read);
	return (line);
}

char	*ft_first_check(int fd)
{
	char	*read;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	return (read);
}

char	*ft_create_line(char *save)
{
	int		len;
	int		i;
	char	*line;

	if (!*save)
		return (NULL);
	len = 0;
	while (save[len] && save[len] != '\n')
		len++;
	len += save[len] == '\n';
	line = ft_calloc (len + 1, sizeof(char));
	if (!line)
		return (NULL);
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
	int		len;
	int		i;
	char	*save_buf;

	if (!*read)
		return (save);
	len = ft_strlen_gnl(read) + ft_strlen_gnl(save);
	save_buf = ft_calloc(len + 1, sizeof(char));
	if (!save_buf)
		return (NULL);
	i = 0;
	while (save && save[i])
	{
		save_buf[i] = save[i];
		i++;
	}
	while (*read)
		save_buf[i++] = *read++;
	save_buf[i] = '\0';
	if (save)
		free (save);
	return (save_buf);
}
