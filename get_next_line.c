#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *line;
    static char *buff[FD_MAX];

    if(fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
        return (NULL);
    buff[fd] = ft_read_line(fd, buff[fd]);
    if(!buff[fd])
        return (NULL);
    line = ft_get_line(buff[fd]);
    buff[fd] = ft_buff_trim(buff[fd]);

    return (line);
}

char *ft_read_line(int fd, char *buff)
{
    char *temp;
    char *read_buff;
    ssize_t bytes_read;

    if(!buff)
        buff = ft_calloc(1, sizeof(char));

    // temp = buff;
    read_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    bytes_read = 1;

    while(!ft_strchr(buff, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, read_buff, BUFFER_SIZE);
        if(bytes_read == -1)
        {
            free(read_buff);
            free(buff);
            read_buff = NULL;
            buff = NULL;
            return (NULL);
        }
        read_buff[bytes_read] = '\0';
        temp = buff;
        buff = ft_strjoin(temp, read_buff);
        free(temp);
        temp = NULL;
    }
    free(read_buff);
    read_buff = NULL;
    return (buff);
}

char *ft_get_line(char *buff)
{
    char *line;
    size_t i = 0;

    if(!buff[i])
        return (NULL);

    while(buff[i] && buff[i] != '\n')
        i++;
    line = ft_calloc(i + 2, sizeof(char));
    i = 0;

    while(*buff && *buff != '\n')
        line[i++] = *buff++;

    if(*buff == '\n')
        line[i] = '\n';

    return (line);
}

char *ft_buff_trim(char *buff)
{
    size_t buff_index = 0;
    size_t line_index = 0;
    char *line;

    while(buff[buff_index] && buff[buff_index] != '\n')
        buff_index++;

    if(!buff[buff_index])
    {
        free(buff);
        buff = NULL;
        return (NULL);
    }
    line = ft_calloc(ft_strlen(buff) - buff_index + 1, sizeof(char));
    buff_index++;

    while(buff[buff_index])
        line[line_index++] = buff[buff_index++];
    free(buff);
    buff = NULL;
    return (line);
}



int	main(void)
{
    int fd = open("file1.txt", O_RDONLY);
    int i = 0;
	while(i < 5)
    {
        char *line = get_next_line(fd);
        printf("line %i: %s\n", i , line);
        free(line);
        i++;
    }

	return (0);
}

