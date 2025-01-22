/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:55 by carlaugu          #+#    #+#             */
/*   Updated: 2025/01/22 11:44:58 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_newline(char *read)
{
	while (*read)
	{
		if (*read == '\n')
			return (1);
		read++;
	}
	return (0);
}

int	ft_strlen_gnl(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t n, size_t size)
{
	size_t	len;
	size_t	i;
	char	*buf;

	len = n * size;
	buf = malloc(len);
	if (!buf)
		return (NULL);
	i = 0;
	while (i < len)
		buf[i++] = 0;
	return (buf);
}

char	*ft_clean_all(char **read, char **save)
{
	if (*save)
		free (*save);
	free (*read);
	*read = NULL;
	*save = NULL;
	return (NULL);
}
