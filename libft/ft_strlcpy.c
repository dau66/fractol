/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:33:00 by ksho              #+#    #+#             */
/*   Updated: 2023/06/11 17:25:36 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;

// 	i = 0;
// 	while (src[i] != '\0')
// 		i++;
// 	if (dstsize == 0)
// 		return (i);
// 	else if (i == dstsize - 1)
// 		ft_memmove(dst, src, i);
// 	else if (i < dstsize - 1)
// 	{
// 		ft_memmove(dst, src, i);
// 		dst[i] = '\0';
// 	}
// 	else if (i > dstsize - 1)
// 		ft_memmove(dst, src, dstsize - 1);
// 	return (i);
// }

// int	main(void)
// {
// 	char	*str;
// 	char	buff2[0xF00];

// 	str = "BBBB";
// 	ft_strlcpy(buff2, str, 0);
// 	printf("%s", buff2);
// }
