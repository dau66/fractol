/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:44:31 by ksho              #+#    #+#             */
/*   Updated: 2023/06/12 20:11:44 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

static size_t	ft_strlen(char *a, size_t size)
{
	size_t	i;

	if (a == NULL && size == 0)
		return (0);
	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst, size);
	src_len = ft_strlen((char *)src, size);
	i = 0;
	if (size < dst_len + 1)
		return (size + src_len);
	if (size > dst_len + 1)
	{
		while (src[i] != '\0' && dst_len + 1 + i < size)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	char *src = "abcd";

// 	int a, b;
// 	a = ft_strlcat(NULL, src, 0);
// 	b = strlcat(NULL, src, 0);

// 	printf("%d %d", a, b);
// }