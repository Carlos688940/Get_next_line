/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:48 by carlaugu          #+#    #+#             */
/*   Updated: 2025/01/22 11:44:46 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*to_read;
	char		*line;
	int			count;
	static char	*to_save;

	to_read = ft_first_check(fd);
	if (!to_read)
		return (NULL);
	count = 1;
	while (!(ft_newline(to_read)) && count)
	{
		count = read(fd, to_read, BUFFER_SIZE);
		if (count < 0)
			return (ft_clean_all(&to_read, &to_save));
		to_read[count] = '\0';
		to_save = ft_create_save(to_read, to_save);
		if (!to_save)
			return (ft_clean_all(&to_read, &to_save));
	}
	line = ft_create_line(to_save);
	if (!line)
		return (ft_clean_all(&to_read, &to_save));
	to_save = ft_clean_save(to_save);
	free (to_read);
	return (line);
}

char	*ft_first_check(int fd)
{
	char	*read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	return (read);
}

char	*ft_create_save(char *read, char *save)
{
	char	*save_buf;
	int		len;
	int		i;
	int		j;

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
	j = 0;
	while (read[j])
		save_buf[i++] = read[j++];
	save_buf[i] = '\0';
	if (save)
		free (save);
	return (save_buf);
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
	len += (save[len] == '\n');
	line = ft_calloc(len + 1, sizeof(char));
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

char	*ft_clean_save(char *save)
{
	int		len;
	int		i;
	int		j;
	char	*new_save;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	len = ft_strlen_gnl(save) - i;
	new_save = ft_calloc(len + (len == 0), sizeof(char));
	if (!new_save)
	{
		free (save);
		return (NULL);
	}
	j = 0;
	if (save[i] == '\n')
	{
		while (save[++i])
			new_save[j++] = save[i];
		new_save[j] = '\0';
	}
	free (save);
	return (new_save);
}
