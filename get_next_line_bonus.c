/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:26:06 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/11 12:21:43 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static	char	*to_save[1024];
	char	*to_read;
	char	*line;
	int	count;
	
	if (fd < 0 || fd > 1024|| BUFFER_SIZE <= 0)
		return (NULL);
	to_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!to_read)
		return (NULL);
	count = 1;
	while (ft_newline(to_read) && count)
	{
		
	}
	return (NULL);
}

void	*ft_calloc(size_t n, size_t size)
{
	char	*buf;
	size_t	len;
	size_t	i;

	len = n * size;
	buf = malloc((len + 1) * sizeof(char));
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

// int	main(void)
// {
// 	get_next_line(1);
// }