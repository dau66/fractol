/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:34:51 by ksho              #+#    #+#             */
/*   Updated: 2023/07/09 14:21:23 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static char	*ft_strd(char *strlows, char *s, char c, size_t j)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && count == j)
		{
			while (*s != c && *s != '\0')
			{
				strlows[i] = *s;
				i++;
				s++;
			}
		}
		while (*s != c && *s != '\0')
			s++;
		count++;
	}
	strlows[i] = '\0';
	return (strlows);
}

static size_t	stringlen(const char *s, char c, size_t j)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			while (*s != c && *s != '\0' && j == count)
			{
				i++;
				s++;
			}
		}
		while (*s != c && *s != '\0')
			s++;
		count++;
	}
	return (i);
}

static size_t	strcount(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
			count++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

static char	**ft_strdup(char const *s, char c, size_t i, char **strrows)
{
	size_t	j;

	j = 0;
	while (i)
	{
		strrows[j] = (char *)malloc(sizeof(char) * stringlen(s, c, j) + 1);
		if (strrows[j] == NULL)
		{
			while (j--)
				free(strrows[j]);
			free(strrows);
			return (NULL);
		}
		strrows[j] = ft_strd(strrows[j], (char *)s, c, j);
		j++;
		i--;
	}
	strrows[j] = NULL;
	return (strrows);
}

char	**ft_split(char const *s, char c)
{
	char	**strrows;
	size_t	i;
	size_t	j;

	j = 0;
	if (s == NULL)
		return (NULL);
	i = strcount((char *)s, c);
	strrows = (char **)malloc(sizeof(char *) * (i + 1));
	if (strrows == NULL)
		return (NULL);
	strrows = ft_strdup(s, c, i, strrows);
	return (strrows);
}
