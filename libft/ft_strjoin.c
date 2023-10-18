/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:25:21 by ksho              #+#    #+#             */
/*   Updated: 2023/07/09 14:23:08 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static char	*ft_strj(char *s1, const char *s2, int start)
{
	size_t	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i + start] = s2[i];
		i++;
	}
	s1[i + start] = '\0';
	return (s1);
}

static size_t	count_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = count_len(s1);
	j = count_len(s2);
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (str == NULL)
		return (NULL);
	str = ft_strj(str, (char *)s1, 0);
	str = ft_strj(str, (char *)s2, i);
	return (str);
}

// int	main(void)
// {
// 	char *str1, *str2, *str3;

// 	str1 = "where is my ";
// 	str2 = "malloc ???";

// 	str3 = ft_strjoin(str1, str2);
// 	printf("%s\n", str3);
// 	free(str3);
// }