int main()
{
	char *line;
	while((line = get_next_line(0)) != NULL) //standard input(from terminal)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}

int main()
{
	char *line;
	int fd = open("file1.txt", O_RDONLY);
	int i = 1;
	while((line = get_next_line(fd)) != NULL)
	{
		printf("line %i: %s\n",i, line);
		free(line);
		i++;
	}
	if(fd < 0)
		printf("file doesn't exist");

	close(fd);
	return (0);
}

int main()
{
	int fd1 = open("bonus1.txt", O_RDONLY);
	int fd2 = open("bonus2.txt", O_RDONLY);
	int fd3 = open("empty.txt", O_RDONLY);
	char *line;
	int i = 0;
	while(i < 3)
	{
		line = get_next_line_bonus(fd1);
		printf("File %i, line %i: %s", 1, i + 1, line);
		free(line);
		line = get_next_line_bonus(fd2);
		printf("File %i, line %i: %s", 2, i + 1, line);
		free(line);
		line = get_next_line_bonus(fd3);
		printf("File %i, line %i: %s", 3, i + 1, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	return (0);
}
