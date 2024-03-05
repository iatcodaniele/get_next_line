/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatco <diatco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:20:10 by diatco            #+#    #+#             */
/*   Updated: 2024/02/13 19:13:36 by diatco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash[fd]);
		return (NULL);
	}
	stash[fd] = ft_read_buffer(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_extract_line(stash[fd]);
	stash[fd] = ft_remove_output_line(stash[fd]);
	return (line);
}

char	*ft_read_buffer(int fd, char *stash)
{
	char	*temp;
	char	*read_line;
	ssize_t	byte;

	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	temp = stash;
	read_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte = 1;
	while (!ft_strchr(stash, '\n') && byte > 0)
	{
		byte = read(fd, read_line, BUFFER_SIZE);
		if (byte == -1)
		{
			free(read_line);
			free(temp);
			return (NULL);
		}
		read_line[byte] = '\0';
		temp = stash;
		stash = ft_strjoin(temp, read_line);
		free(temp);
	}
	free(read_line);
	return (stash);
}

char	*ft_extract_line(char *stash)
{
	char	*new_line;
	size_t	line_index;
	size_t	stash_index;

	line_index = 0;
	stash_index = 0;
	if (!stash[stash_index])
		return (NULL);
	else
		while (stash[stash_index] && stash[stash_index] != '\n')
			stash_index++;
	new_line = ft_calloc(stash_index + 2, sizeof(char));
	stash_index = 0;
	while (stash[stash_index] && stash[stash_index] != '\n')
	{
		new_line[line_index++] = stash[stash_index++];
	}
	if (stash[stash_index] == '\n')
		new_line[line_index] = '\n';
	return (new_line);
}

char	*ft_remove_output_line(char *stash)
{
	char	*leftover;
	size_t	stash_index;
	size_t	leftover_index;

	stash_index = 0;
	leftover_index = 0;
	while (stash[stash_index] && stash[stash_index] != '\n')
		stash_index++;
	if (stash[stash_index] == '\0')
	{
		free(stash);
		return (NULL);
	}
	leftover = ft_calloc(ft_strlen(stash) - stash_index + 1, sizeof(char));
	stash_index++;
	while (stash[stash_index] != '\0')
		leftover[leftover_index++] = stash[stash_index++];
	free(stash);
	return (leftover);
}
// #include <time.h>
// int main()
// {
// 	int fd1 = open("image.txt", O_RDONLY);
// 	int fd2 = open("long_no_nl.txt", O_RDONLY);
// 	int fd3 = open("onlynewline.txt", O_RDONLY);
// 	clock_t tic = clock();
// 	int i = 0;
// 	char *line;
// 	while(i < 32)
// 	{
// 		line = get_next_line(fd1);
// 		printf("File %i, line %i: %s\n", 1, i+1, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("File %i, line %i: %s\n", 2, i+1, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("File %i, line %i: %s\n", 3, i+1, line);
// 		free(line);
// 		i++;
// 	}
// 	clock_t toc = clock();
// 	printf("duration: %f", (double)(toc - tic) / CLOCKS_PER_SEC);
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }
