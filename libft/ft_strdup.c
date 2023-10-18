/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:11:26 by ksho              #+#    #+#             */
/*   Updated: 2023/07/09 14:23:20 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(src);
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}

// int	main(void)
// {
// 	char *s;

// 	s = ft_strdup("\0");
// 	printf("s = %s\n", s);
// 	free(s);

// 	s = strdup("\0");
// 	printf("s = %s\n", s);
// 	free(s);

// 	return (0);
// }
