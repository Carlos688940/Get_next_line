/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:09:55 by carlaugu          #+#    #+#             */
/*   Updated: 2025/01/22 11:56:20 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 800

# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_clean_all(char **read, char **save);
char	*ft_create_save(char *read, char *save);
char	*ft_create_line(char *save);
char	*ft_clean_save(char *save);
char	*ft_first_check(int fd);
void	*ft_calloc(size_t n, size_t size);
int		ft_newline(char *read);
int		ft_strlen_gnl(char *s);

#endif
