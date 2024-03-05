/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatco <diatco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:35:39 by diatco            #+#    #+#             */
/*   Updated: 2024/02/13 20:21:12 by diatco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		return (NULL);
	}
	stash = ft_read_buffer(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_extract_line(stash);
	stash = ft_remove_output_line(stash);
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
// 	char *line;
// 	int fd = open("bigben.txt", O_RDONLY);
// 	int i = 1;
// 	clock_t tic = clock();
// 	while((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("line %i: %s\n",i, line);
// 		free(line);
// 		i++;
// 	}
// 	if(fd < 0)
// 		printf("file doesn't exist");
// 	clock_t toc = clock();
// 	printf("duration: %f\n", (double)(toc -tic) / CLOCKS_PER_SEC);
// 	close(fd);
// 	return (0);
// }
// int main()
// {
// 	char *line;
// 	while((line = get_next_line(0)) != NULL) //standard input(from terminal)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	return (0);
// }
