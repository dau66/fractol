/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:04:44 by ksho              #+#    #+#             */
/*   Updated: 2023/10/24 05:26:25 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	treat_point_sum(char *str, double sign)
{
	double	n;
	double	point_sum;

	n = 1;
	point_sum = 0.0;
	while ('0' <= *str && *str <= '9')
	{
		point_sum = point_sum + (sign * pow(0.1, n)) * (*str - '0');
		n++;
		str++;
	}
	return (sign * point_sum);
}

static double	over_max_che(char *str, double sign)
{
	double	i;

	i = 0.0;
	while ('0' <= *str && *str <= '9')
	{
		if (i > DBL_MAX / 10.0)
			error_output();
		i = i * 10.0;
		if (i > DBL_MAX - (*str - '0'))
			error_output();
		i = i + (*str - '0');
		str++;
		if (*str == '.')
		{
			str++;
			if (treat_point_sum(str, sign) > DBL_MAX - i)
				error_output();
			i += treat_point_sum(str, sign);
			break ;
		}
	}
	return (i * sign);
}

static double	over_min_che(char *str, double sign)
{
	double	i;

	i = 0.0;
	while ('0' <= *str && *str <= '9')
	{
		if (i * sign < -DBL_MAX / 10)
			error_output();
		i = 10.0 * i;
		if (i * sign < -DBL_MAX + (*str - '0'))
			error_output();
		i = i + (*str - '0');
		str++;
		if (*str == '.')
		{
			str++;
			if (sign * treat_point_sum(str, sign) < -DBL_MAX - (i * sign))
				error_output();
			i += treat_point_sum(str, sign);
			break ;
		}
	}
	return (i * sign);
}

double	ft_atod(char *nptr)
{
	double	sign;
	double	i;

	sign = 1.0;
	i = 0.0;
	while ((8 < *nptr && *nptr < 14) || (*nptr == 32))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1.0;
		nptr++;
	}
	if (47 < *nptr && *nptr < 58)
	{
		if (sign < 0.0)
			i = over_min_che(nptr, sign);
		else
			i = over_max_che(nptr, sign);
	}
	else
		error_output();
	return (i);
}
