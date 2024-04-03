/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:37:04 by ksho              #+#    #+#             */
/*   Updated: 2023/06/08 18:28:22 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

//strtol関数実装したほうがはやい
static long	over_max_che(char *str, int sign)
{
	long	i;

	i = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (i > LONG_MAX / 10)
			return (LONG_MAX);
		i = i * 10;
		if (i > LONG_MAX - (*str - '0'))
			return (LONG_MAX);
		i = i + *str - '0';
		str++;
	}
	return (i * sign);
}

static long	over_min_che(char *str, int sign)
{
	long	i;

	i = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (i * sign < LONG_MIN / 10)
			return (LONG_MIN);
		i = 10 * i;
		if (i * sign < LONG_MIN + (*str - '0'))
			return (LONG_MIN);
		i = i + *str - '0';
		str++;
	}
	return (i * sign);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	i;

	sign = 1;
	i = 0;
	while ((8 < *nptr && *nptr < 14) || (*nptr == 32))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	if (47 < *nptr && *nptr < 58)
	{
		if (sign < 0)
			i = over_min_che((char *)nptr, sign);
		else
			i = over_max_che((char *)nptr, sign);
	}
	return ((int)i);
}

// int	main(void)
// {
// 	char str[100] = "   \n\t\v\f\r 2147483647";
// 	int num;

// 	// 文字列型からint型への変換
// 	num = ft_atoi(str);
// 	printf("int型変数numの値は: %d\n", num);

// 	return (0);
// }