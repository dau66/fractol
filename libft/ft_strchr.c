/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:28:57 by ksho              #+#    #+#             */
/*   Updated: 2023/07/07 17:29:04 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	find;
	size_t	i;

	find = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (NULL);
}

// int	main(void)
// {
// 	char test[20] = "abcdefghijk";
// 	char *p;

// 	p = ft_strchr(test,'h');

// 	printf("検索文字が見つかった場所から表示→%s\n",p);

// 	return (0);
// }
