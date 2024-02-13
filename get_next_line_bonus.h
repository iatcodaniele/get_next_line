/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatco <diatco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:20:51 by diatco            #+#    #+#             */
/*   Updated: 2024/02/13 18:29:33 by diatco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>

char	*get_next_line(int fd);
char	*ft_read_buffer(int fd, char *stash);
char	*ft_extract_line(char *stash);
char	*ft_remove_output_line(char *stash);

int		ft_strlen(const char *str);
void	ft_bzero(void *p, size_t n);
void	*ft_calloc(size_t n_elem, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
