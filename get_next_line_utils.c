#include "get_next_line.h"

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

void *ft_calloc(size_t n, size_t size)
{
	void *array;

	array = malloc(n * size);
	if(!array)
		return (NULL);
	else
		ft_bzero(array, n * size);
	return (array);
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}

char *ft_strchr(const char *str, int c)
{
	int i = 0;
	unsigned char a = c;
	char *s = (char *)str;
	if(a == '\0')
		return (s + ft_strlen(s));

	while(s[i])
	{
		if(s[i] == a)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char *ft_strjoin(char *s1, char *s2)
{
	unsigned int i = 0;
	unsigned int j = 0;
	char *string = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if(!string)
		return (NULL);
	while(s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	while(s2[i])
	{
		string[i+j] = s2[j];
		j++;
	}
	string[i+j] = '\0';
	return (string);
}
