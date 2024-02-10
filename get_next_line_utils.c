#include "get_next_line.h"

int ft_strlen(const char *str)
{
	int i = 0;

	while(str[i])
		i++;

	return (i);
}

void ft_bzero(void *array, size_t n)
{
	unsigned char *p = array;
	size_t i = 0;

	while(i < n)
	{
		*p++ = 0;
		n--;
	}
}

void *ft_calloc(size_t nmemb, size_t size)
{
	void *array;

	array = malloc(nmemb * size);
	if(!array)
		return NULL;
	else
		ft_bzero(array, nmemb * size);

	return (array);
}
char *ft_strchr(const char *s, int c)
{
	size_t i = 0;
	char *str = (char *)s;
	unsigned char a = (char)c;

	if(a == '\0')
		return (str + ft_strlen(str));

	while(*str)
	{
		if(str[i] == a)
		{
			return (&str[i]);
		}
		str++;
	}
	return (NULL);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	int j = 0;
	int i = 0;
	char *array = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if(!array)
		return NULL;

	while(s1[i] != '\0')
	{
		array[i] = s1[i];
		i++;
	}
	while(s2[j] != '\0')
	{
		array[i+j] = s2[j];
		j++;
	}
	array[i + j] = '\0';
	return (array);
}
