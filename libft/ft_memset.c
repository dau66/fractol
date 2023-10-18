/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:20:25 by ksho              #+#    #+#             */
/*   Updated: 2023/06/11 17:06:12 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// #include<stdio.h>
// #include <string.h>

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)buf;
	while (i < n)
	{
		*str = (unsigned char)ch;
		str++;
		i++;
	}
	return (buf);
}

// int	main(void)
// {
// 	char str[] = "0123456789";
// 	size_t n = 5;
// 	// memset(str + 2, '*', n);
// 	ft_memset(str + 2, '*', n);
// 	printf("%s\n", str);

// 	return (0);
// }