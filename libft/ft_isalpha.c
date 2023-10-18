/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:49:06 by ksho              #+#    #+#             */
/*   Updated: 2023/05/16 16:12:50 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>
// #include <unistd.h>

int	ft_isalpha(int a)
{
	if ((64 < a && a < 91) || (96 < a && a < 123))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	int	num;
// 	int	num1;

// 	num = isalpha('A');
// 	num1 = ft_isalpha('A');
// 	printf("%d %d", num, num1);
// }
