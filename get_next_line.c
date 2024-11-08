/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:48 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/08 21:11:48 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*ptr;
	size_t	len;
	size_t	i;

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

int	ft_strlen(char *s)
{
	size_t	i;

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
	if (!save)
	{
		free (read);
	}
	else
	{
		free (read);
		free (save);
	}
	return (NULL);
}

char	*ft_create_save(char *read, char *save)
{
	size_t	len;
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!save)
	{
		save = ft_calloc(1, sizeof(char));
		if (!save)
			return (ft_clean_all(read, save));
	}
	len = ft_strlen(read) + ft_strlen(save);
	ptr = ft_calloc((len + 1), sizeof(char));
	if (!ptr)
		return (ft_clean_all(read, save));
	i = 0;
	while (save[i])
	{
		ptr[i] = save[i];
		i++;
	}
	j = 0;
	while (read[j])
		ptr[i++] = read[j++];
	ptr[i] = '\0';
	free (save);
	return (ptr);
}

char	*ft_create_line(char *read, char *save)
{
	size_t	len;
	size_t	i;
	char	*line;

	len = 0;
	if (!*save)
		return (NULL);
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

char	*ft_clean_save(char *read, char *save)
{
	size_t	i;
	size_t	j;
	size_t	len;
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
	while (save[i])
	{
		if (save[i] == '\n')
			i++;
		new_save[j++] = save[i];
		i++;
	}
	new_save[j] = '\0';
	free (save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	char	*to_read;
	static char	*to_save;
	char	*line;
	size_t	count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	to_read = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
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
	}
	line = ft_create_line(to_read, to_save);
	if (!line)
		return (NULL);
	to_save = ft_clean_save(to_read, to_save);
	free(to_read);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include "get_next_line.h"  // Certifique-se de que o caminho está correto


// int main() {
//     int fd;
//     char *line;

//     // Abre o arquivo de teste
//     fd = open("test.txt", O_RDONLY);  // Substitua "teste.txt" pelo nome do arquivo que deseja usar
//     if (fd == -1) {
//         perror("Erro ao abrir o arquivo");
//         return 1;
//     }

//     // Chama get_next_line para ler o arquivo linha por linha
//     while ((line = get_next_line(fd)) != NULL) {
//         printf("Linha lida: %s", line);  // Imprime a linha lida
//         free(line);  // Libera a memória após usar
//     }

//     // Fecha o arquivo
//     close(fd);

//     return 0;
// }
