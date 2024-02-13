/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatco <diatco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:20:03 by diatco            #+#    #+#             */
/*   Updated: 2024/02/13 18:28:26 by diatco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *p, size_t n)
{
	unsigned char	*s;
	size_t			i;

	s = p;
	i = 0;
	while (i < n)
	{
		*s++ = 0;
		n--;
	}
}

void	*ft_calloc(size_t n_elem, size_t size)
{
	void	*array;

	array = malloc(n_elem * size);
	if (!array)
		return (NULL);
	else
		ft_bzero(array, n_elem * size);
	return (array);
}

char	*ft_strchr(const char *str, int c)
{
	char			*s;
	unsigned char	a;
	size_t			i;

	i = 0;
	a = c;
	s = (char *)str;
	if (a == '\0')
		return (s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == a)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*array;
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	array = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!array)
		return (NULL);
	while (s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		array[i + j] = s2[j];
		j++;
	}
	array[i + j] = '\0';
	return (array);
}
