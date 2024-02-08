#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFFER_SIZE 5
#define FD_MAX 8

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdio.h>

char	*get_next_line(int fd);
char *ft_read_line(int fd, char *buff);
char *ft_get_line(char *buff);
char *ft_buff_trim(char *buff);
char	*ft_strchr(const char *s, int c);
int ft_strlen(char *str);
void ft_bzero(void *s, size_t n);
void *ft_calloc(size_t number, size_t size);
char *ft_strjoin(char *s1, char *s2);

#endif
