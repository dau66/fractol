/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:11:15 by ksho              #+#    #+#             */
/*   Updated: 2023/07/09 16:56:20 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*str;
	const char	*str1;

	i = 0;
	str = (char *)dst;
	str1 = (const char *)src;
	if (str1 == (void *)0 && str == NULL)
		return (NULL);
	while (i < n)
	{
		*str = *str1;
		str++;
		str1++;
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str1[128];
// 	int		i;

// 	// str1[128] = {1};
// 	char str2[] = -1; /* 途中に空文字のある文字列 */
// 	printf("コピー前　中身の確認\n");
// 	for (i = 0; i < 7; i++)
// 		printf("%#x ", str1[i]);
// 	printf("\n");
// 	memcpy((void*)0, (void*)0, 5);
// 	// ft_memcpy("            ", ((void *)0), 17);
// 	printf("コピー後　中身の確認\n");
// 	for (i = 0; i < 7; i++)
// 		printf("%#x ", str1[i]);
// 	printf("\n");
// 	return (0);
// }
