#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *line;
	static char *stash[fd_max];

	if(fd < 0 || BUFFER_SIZE <= 0 || fd >= fd_max)
		return NULL;

	stash[fd] = ft_find_line(fd, stash[fd]);
	if(!stash[fd])
		return NULL;
	line = ft_extract_line(stash[fd]);
	stash[fd] = ft_remove_previous_line(stash[fd]);

	return (line);
}

char *ft_find_line(int fd, char *stash)
{
	char *temp;
	char *line_read;
	ssize_t bytes;

	if(!stash)
		stash = ft_calloc(1, sizeof(char));
	temp = stash;
	line_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes = 1;
	while(!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, line_read, BUFFER_SIZE);
		if(bytes == -1)
		{
			free(line_read);
			free(temp);
			return NULL;
		}
		line_read[bytes] = '\0';
		temp = stash;
		stash = ft_strjoin(temp, line_read);
		free(temp);
	}
	free(line_read);
	return (stash);
}

char *ft_extract_line(char *stash)
{
	char *line;
	size_t i;
	i = 0;

	if(stash[i] == '\0')
		return NULL;
	else
	{
		while(stash[i] && stash[i] != '\n')
		i++;
	}
	line = ft_calloc(i + 2, sizeof(char));

	i = 0;
	while(*stash && *stash != '\n')
	{
		line[i++] = *stash++;
	}

	if(*stash == '\n')
		line[i] = '\n';

	return (line);
}

char *ft_remove_previous_line(char *stash)
{
	char *line;
	size_t stash_index = 0;
	size_t line_index = 0;

	while(stash[stash_index] && stash[stash_index]!= '\n')
		stash_index++;
	if(stash[stash_index] == '\0')
	{
		free(stash);
		return NULL;
	}
	line = ft_calloc(ft_strlen(stash) - stash_index + 1, sizeof(char));
	stash_index++;
	while(stash[stash_index])
		line[line_index++] = stash[stash_index++];
	free(stash);
	return (line);
}

int main()
{
	int fd = open("/nfs/homes/diatco/Desktop/trash/get_next_line_v3/file.txt", O_RDWR);
	int i = 0;
	char *line = get_next_line(fd);
	printf("%s \n", line);

	while(i < 3)
	{
		printf("line number %i: %s \n", i, line);
		free(line);
		i++;
	}
}

