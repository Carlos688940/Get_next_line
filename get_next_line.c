/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:48 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/09 16:44:23 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_create_save(char *read, char *save)
{
	char	*ptr;
	int		len;
	int		i;
	int		j;

	if (!*read)
		return (save);
	len = ft_strlen(read) + ft_strlen(save);
	ptr = ft_calloc((len + 1), sizeof(char));
	if (!ptr)
		return (ft_clean_all(read, save));
	i = 0;
	while (save && save[i])
	{
		ptr[i] = save[i];
		i++;
	}
	j = 0;
	while (read[j])
		ptr[i++] = read[j++];
	ptr[i] = '\0';
	if (save)
		free (save);
	return (ptr);
}

char	*ft_create_line(char *read, char *save)
{
	int		len;
	int		i;
	char	*line;

	len = 0;
	while (save[len] && save[len] != '\n')
		len++;
	len += (save[len] == '\n');
	line = ft_calloc(len + 1, sizeof(char));
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

char	*ft_first_check(int fd)
{
	char	*read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	return (read);
}

char	*get_next_line(int fd)
{
	static char	*to_save;
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
			return (ft_clean_all(to_read, to_save));
		to_read[count] = '\0';
		to_save = ft_create_save(to_read, to_save);
		if (!to_save)
			return (NULL);
	}
	line = ft_create_line(to_read, to_save);
	if (!line)
		return (NULL);
	to_save = ft_clean_save(to_read, to_save);
	free(to_read);
	return (line);
}
