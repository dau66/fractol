/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:53:59 by ksho              #+#    #+#             */
/*   Updated: 2023/07/07 17:26:41 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_digit(int i)
{
	int	j;

	j = 0;
	if (i <= 0)
		j++;
	while (i != 0)
	{
		i /= 10;
		j++;
	}
	return (j);
}

static char	*ft_sum(char *str, long j, int digit)
{
	while (j)
	{
		str[digit] = j % 10 + '0';
		j = j / 10;
		digit--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*numstr;
	size_t	i;
	long	j;
	int		digit;

	digit = ft_digit(n);
	i = 0;
	j = (long)n;
	numstr = (char *)malloc(sizeof(char) * digit + 1);
	if (numstr == NULL)
		return (NULL);
	if (j < 0)
	{
		numstr[i] = '-';
		j *= -1;
	}
	numstr[digit] = '\0';
	if (j == 0)
		numstr[digit - 1] = j + '0';
	else
		numstr = ft_sum(numstr, j, digit - 1);
	return (numstr);
}

// int	main(void)
// {
// 	int n;
// 	n = 0;

// 	char *str;
// 	str = ft_itoa(n);
// 	printf("%s\n", str);
// 	free(str);
// }