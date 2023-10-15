/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:59:30 by ksho              #+#    #+#             */
/*   Updated: 2023/10/15 20:09:38 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel(t_data *data)
{
	int		i;
	int		j;
	int		k;
	double	x;
	double	y;
	double	a;
	double	b;
	double	_a;
	double	_b;

	i = 0;
	j = 0;
	for (i = 0; PIXEL > i; i++)
	{
		x = (double)((double)i * (double)(SIZE)) / (double)PIXEL
			- ((double)((double)SIZE / 2.0));
		for (j = 0; PIXEL > j; j++)
		{
			y = (double)((double)j * (double)SIZE) / (double)PIXEL
				- (double)((double)SIZE / 2.0);
			a = 0;
			b = 0;
			for (k = 0; C_COUNT > k; k++)
			{
				// printf("x:%f y:%f\n", x, y);
				_a = a;
				_b = b;
				a = pow(_a, 2.0) - pow(_b, 2.0) + x;
				b = (double)2 * _a * _b + y;
				// printf("a:%d b:%d\n",(int)a,(int)b);
				if ((pow(a, 2.0) + pow(b, 2.0)) > 4.0)
				{
					my_mlx_pixel_put(data, i, j, create_trgb((2.0 * k), 0, 0,
								255 - (2.5 * k)));
				}
			}
		}
	}
}

// while(i < PIXEL)
// {
// 	while(j < PIXEL)
// 	{
// 		k = create_trgb(i,0,j);
// 		my_mlx_pixel_put(data, i, j, k);
// 		j ++;
// 	}
// 	i ++;
// 	j = 0;
// }