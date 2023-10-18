/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:25:46 by ksho              #+#    #+#             */
/*   Updated: 2023/05/21 15:33:52 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		str++;
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*p;

// 	char str[256] = "abcderf"; /* 途中に空文字のある文字列 */
// 	p = ft_memchr(str, 'e' - 256, 256);
// 	printf("検索文字は文字列の%ld番目\n", p - str);
// 	return (0);
// }
