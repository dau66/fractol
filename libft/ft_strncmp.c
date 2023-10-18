/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:05:08 by ksho              #+#    #+#             */
/*   Updated: 2023/06/06 14:43:05 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (len--)
	{
		if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0')
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
// #include <string.h>
// #include <stdio.h>

// int main(void)
// {

// 	char test1[10] = "abc12";
// 	char test2[10] = "abcde";

// 	//test1とtest2の文字列を先頭から5文字比較
// 	if(ft_strncmp(test1,test2,5)==0){
// 		puts("文字列は一致しています。");
// 	}else{
// 		puts("文字列は一致していません。");
// 	}

// 	//test1とtest2の文字列を先頭から３文字比較
// 	if(ft_strncmp(test1,test2,3)==0){
// 		puts("文字列は一致しています。");
// 	}else{
// 		puts("文字列は一致していません。");
// 	}

// 	return (0);
// }