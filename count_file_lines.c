int count_lines(char *filename)
{
	FILE *file = fopen(filename, "r");
	if(file == NULL){
		printf("failed to open file %s\n", filename);
		return (-1);
	}

	int count = 0;
	char ch;
	while((ch = fgetc(file)) != EOF){
		if(ch == '\n')
			count++;
	}
	fclose(file);
	return (count);
}

#include <time.h>
int main()
{
	int fd1 = open("standart.txt", O_RDONLY);
	int fd2 = open("twolines.txt", O_RDONLY);
	int fd3 = open("empty.txt", O_RDONLY);
	int lines1 = count_lines("standart.txt");
	int lines2 = count_lines("twolines.txt");
	int lines3 = count_lines("empty.txt");
	int max_lines = lines1;
	if(lines2 > max_lines)
		max_lines = lines2;
	if(lines3 > max_lines)
		max_lines = lines3;
	char *line;
	int i = 0;
	clock_t tic = clock();
	while(i < max_lines)
	{
		line = get_next_line(fd1);
		printf("File %i, line %i: %s\n", 1, i + 1, line);
		free(line);
		line = get_next_line(fd2);
		printf("File %i, line %i: %s\n", 2, i + 1, line);
		free(line);
		line = get_next_line(fd3);
		printf("File %i, line %i: %s\n", 3, i + 1, line);
		free(line);
		i++;
	}
	clock_t toc = clock();
	printf("duration: %f", (double)(toc - tic) / CLOCKS_PER_SEC);
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
