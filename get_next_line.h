#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#define BUFFER_SIZE 3
#define fd_max 7

char *get_next_line(int fd);
char *ft_find_line(int fd, char *stash);
char *ft_extract_line(char *stash);
char *ft_remove_previous_line(char *stash);

int ft_strlen(char const *str);
void ft_bzero(void *array, size_t n);
void *ft_calloc(size_t nmemb, size_t size);
int ft_strchr(const char *s, int c);
char *ft_strjoin(char const *s1, char const *s2);

#endif
