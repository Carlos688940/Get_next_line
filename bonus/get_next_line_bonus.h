/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:09:55 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/11 16:43:51 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3

#endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t n, size_t size);
int	ft_newline(char	*read);
char	*ft_clean_all(char *read, char *save);
char	*ft_create_save(char *read, char *save);
size_t	ft_strlen(char *s);
char	*ft_create_line(char *read, char *save);
char	*ft_clean_save(char *read, char *save);

#endif