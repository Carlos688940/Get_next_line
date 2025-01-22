/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:31:35 by carlaugu          #+#    #+#             */
/*   Updated: 2025/01/22 11:46:14 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_clean_all(char **read, char **save)
{
	if (*save)
		free (*save);
	free (*read);
	*read = NULL;
	*save = NULL;
	return (NULL);
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

char	*ft_clean_save(char *save)
{
	int		i;
	int		j;
	int		len;
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
