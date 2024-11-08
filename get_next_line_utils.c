/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:55 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/08 11:35:49 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t			len;
	size_t			i;
	unsigned char	*ptr;

	if (n == 0 || size == 0)
		return (malloc(0));
	len = n * size;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

int	ft_newline(char *read_buf)
{
	if (!read_buf)
		return (0);
	while (*read_buf)
	{
		if (*read_buf == '\n')
			return (1);
		read_buf++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_clean_save(char *save, char *read)
{
	size_t	i;
	size_t	j;
	size_t	new_save_len;
	char	*new_save;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (NULL);
	new_save_len = (ft_strlen(save) - i) - 1;
	new_save = ft_calloc(new_save_len + 1, sizeof(char));
	if (!new_save)
		return (ft_clean_all(read, save));
	j = 0;
	while (save[i])
		new_save[j++] = save[++i];
	free (save);
	return (new_save);
}

char	*ft_clean_all(char *read_buf, char *save_buf)
{
	if (!save_buf)
	{
		free (read_buf);
	}
	else
	{
		free(read_buf);
		free(save_buf);
	}
	return (NULL);
}
