/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:06:10 by ksho              #+#    #+#             */
/*   Updated: 2023/06/11 17:05:52 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// #include<stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str1;

	i = 0;
	str = (unsigned char *)dst;
	str1 = (unsigned char *)src;
	if (str < str1)
	{
		while (i < len)
		{
			str[i] = str1[i];
			i++;
		}
	}
	else if (str > str1)
	{
		i = len;
		while (i-- > 0)
			str[i] = str1[i];
	}
	return (dst);
}

// #include        <stdio.h>
// #include        <string.h>

// int main(void)
// {
//         char str[] = "abcdefghijklmnopqrstu";

//         printf("移動前：%s\n",str);

//         ft_memmove(str+5, str, 10);        /* 重複エリアのコピー */

//         printf("移動後：%s\n",str);

//         return (0);
// }
