/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:15:14 by ksho              #+#    #+#             */
/*   Updated: 2023/05/17 14:37:16 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
#include <stdio.h>

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	int a, b;
// 	scanf("%d", &a);
// 	b = isprint(a);
// 	printf("%d\n", b);
// 	b = ft_isprint(a);
// 	printf("%d", b);
// }