/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:16:26 by ksho              #+#    #+#             */
/*   Updated: 2023/06/08 18:35:26 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// void	doubleChar(unsigned int index, char *c)
// {
// 	if (index == 2)
// 		c[index]++;
// 	else
// 		c[index] += 0;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	if (s != NULL && f != NULL)
	{
		i = ft_strlen(s);
		while (j < i)
		{
			(*f)(j, &s[j]);
			j++;
		}
	}
}

// int	main(void)
// {
// 	char *a;
// 	void (*b)(unsigned int, char *);
// 	a = "abcdeF";

// 	printf("%s\n", a);
// 	ft_striteri(a, b);
// 	printf("%s\n", a);
// }