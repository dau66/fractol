/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:09:57 by ksho              #+#    #+#             */
/*   Updated: 2023/10/23 18:19:17 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static void	calculate_complex_square(double *a, double *b)
{
	double	_a;

	_a = *a;
	*a = pow(_a, 2.0) - pow(*b, 2.0);
	*b = (double)2 * _a * (*b);
}

// static void	calculate_pixel_coordinates(int i, int j, double *x, double *y)
// {
// 	*x = ((double)i * SIZE / PIXEL) - (SIZE / 2.0);
// 	*y = ((double)(PIXEL - j) * SIZE / PIXEL) - (SIZE / 2.0);
// }

static int	is_julia(double a, double b, double first_x, double first_y)
{
	double	_a;
	double	_b;
	int		k;

	k = 0;
	while (k < C_COUNT)
	{
		_a = a;
		_b = b;
		calculate_complex_square(&a, &b);
		a += first_x;
		b += first_y;
		if ((pow(a, 2.0) + pow(b, 2.0)) > 4.0)
			return (k);
		k++;
	}
	return (-1);
}

void	julia(t_windows *data, double first_x, double first_y)
{
	int		i;
	int		j;
	int		k;
	double	x;
	double	y;

	i = 0;
	data->what_sets = 'j';
	while (i < PIXEL)
	{
		j = 0;
		while (j < PIXEL)
		{
			x = (double)i * (SIZE * pow(1.1, data->zoom_in_out)) / (double)PIXEL
				- (SIZE * pow(1.1, data->zoom_in_out) / 2.0);
			y = (double)j * (SIZE * pow(1.1, data->zoom_in_out)) / (double)PIXEL
				- (SIZE * pow(1.1, data->zoom_in_out) / 2.0);
			k = is_julia(x, y, first_x, first_y);
			if (k != -1)
				my_mlx_pixel_put(data, i, j, hsv_to_rgb((data->change_color + 20
							* k), 100, 100));
			j++;
		}
		i++;
	}
}
