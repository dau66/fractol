/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:48:01 by ksho              #+#    #+#             */
/*   Updated: 2023/06/08 18:23:16 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	char	find;
	size_t	i;

	s1 = (char *)s;
	find = (unsigned char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s1[i] == find)
			return (s1 + i);
		i--;
	}
	if (s1[i] == find)
		return (s1);
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {

// 	char test[20] = "123456321";
// 	char *p;

// 	p = ft_strrchr(test,'5');

// 	printf("検索文字が見つかった場所から表示→%s\n",p);

// 	return (0);
// }