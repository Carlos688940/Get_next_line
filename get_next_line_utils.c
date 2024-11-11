/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:55 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/11 21:37:59 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*ptr;
	size_t		len;
	size_t		i;

	len = n * size;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
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

char	*ft_clean_all(char *read, char *save)
{
	if (save)
		free(save);
	free (read);
	return (NULL);
}

char	*ft_clean_save(char *read, char *save)
{
	size_t		i;
	size_t		j;
	size_t		len;
	char	*new_save;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	len = (ft_strlen(save) - i);
	if (!len)
	{
		free (save);
		return (NULL);
	}
	new_save = ft_calloc(len, sizeof(char));
	if (!new_save)
		return (ft_clean_all(read, save));
	j = 0;
	while (save[++i])
		new_save[j++] = save[i];
	new_save[j] = '\0';
	free (save);
	return (new_save);
}
