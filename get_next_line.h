/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:51 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/07 21:27:48 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3

# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t n, size_t size);
int		ft_newline(char *buf);
size_t	ft_strlen(const char *s);
char	*ft_addchars(char *buf, char *save);
char	*ft_clean_all(char *read, char *save);
char	*ft_create_line(char *save, char *read);
char	*ft_clean_save(char *save, char *read);

#endif