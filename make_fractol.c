/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:59:30 by ksho              #+#    #+#             */
/*   Updated: 2023/10/13 20:07:58 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	m_fractol(t_data *data)
{
	int i;
	int j;
	int k;
	double x;
	double y;
	double a;
	double b;

	i = 0;
	j = 0;
	for (i = 0; PIXEL > i; i++)
	{
		x = (i * SIZE) / (double)PIXEL - (SIZE / 2.0);
		for (j = 0; PIXEL > j; j++)
		{
			y = (j * SIZE) / (double)PIXEL - (SIZE / 2.0);
			my_mlx_pixel_put(data, i, j, (int)((x + 2) / (double)SIZE * 255));
			break ;
			a = 0;
			b = 0;
			for (k = 0; 1000 > k; k++)
			{
				a = a * a - b * b + x;
				b = 2 * a * b + y;
				if (a * a + b * b > 4.0)
				{
					my_mlx_pixel_put(data, i, j, 255);
					break ;
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
}