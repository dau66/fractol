/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:08:34 by ksho              #+#    #+#             */
/*   Updated: 2023/07/09 16:51:05 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static size_t	judge(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	length;
	char	*newstr;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	j = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && judge(s1[i], set))
		i++;
	while (j > i && judge(s1[j], set))
		j--;
	length = j - i + 1;
	newstr = (char *)malloc(sizeof(char) * (length + 1));
	if (newstr == NULL)
		return (NULL);
	j = 0;
	while (j < length)
	{
		newstr[j] = s1[j + i];
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}

// int	main(void)
// {
// 	const char *str1 = " \n\t\r    hello \n\t\r world     \r\t\n\t \r\n";
// 	const char *str2 = " \n\t\r";
// 	char *str3 = ft_strtrim(str1, str2);
// 	printf("%s\n", str3);
// 	free(str3);
// 	return (0);
// }