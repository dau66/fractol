/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:59:30 by ksho              #+#    #+#             */
/*   Updated: 2023/10/18 21:59:13 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	calculate_complex_square(double *a, double *b)
{
	double	_a;

	_a = *a;
	*a = pow(_a, 2.0) - pow(*b, 2.0);
	*b = (double)2 * _a * (*b);
}

void	calculate_pixel_coordinates(int i, int j, double *x, double *y)
{
	*x = (double)i * SIZE / PIXEL - SIZE / 2.0;
	*y = (double)j * SIZE / PIXEL - SIZE / 2.0;
}

int	is_mandelbrot(double x, double y)
{
	double	a;
	double	b;
	int		k;
	double	_a;
	double	_b;

	a = 0;
	b = 0;
	k = 0;
	while (k < C_COUNT)
	{
		_a = a;
		_b = b;
		calculate_complex_square(&a, &b);
		a += x;
		b += y;
		if ((pow(a, 2.0) + pow(b, 2.0)) > 4.0)
			return (k);
		k++;
	}
	return (-1);
}

void	mandel(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < PIXEL)
	{
		j = 0;
		while (j < PIXEL)
		{
			double x;
			double y;
			calculate_pixel_coordinates(i, j, &x, &y);
			k = is_mandelbrot(x, y);
			if (k != -1)
				my_mlx_pixel_put(data, i, j, hsv_to_rgb(10 * k, 50, 50));
			j++;
		}
		i++;
	}
}

