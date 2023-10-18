/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:24:09 by ksho              #+#    #+#             */
/*   Updated: 2023/06/11 16:16:14 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char buf1[] = "\xff\xaa\xde\xffMACOSX\xff"; /* 途中に空文字のある文字列 */
// 	char buf2[] = "\xff\xaa\xde\x02";
// 	char buf3[] = "\0abcdef";

// 	int i, j, k;

// 	i = ft_memcmp(buf1, buf2, 8);
// 	printf("%d\n", i);
// 	return (0);
// }