/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:51 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/14 00:24:42 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3

# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_clean_all(char **read, char **save);
char	*ft_create_save(char *read, char *save);
char	*ft_create_line(char *save);
char	*ft_clean_save(char *save);
char	*ft_first_check(int fd);
void	*ft_calloc(size_t n, size_t size);
int		ft_newline(char *read);
int		ft_strlen(char *s);

#endif