/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:09:57 by ksho              #+#    #+#             */
/*   Updated: 2023/10/15 20:18:18 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void julia(t_data *data, double first_x, double first_y)
{
    int i, j, k;
    double x, y, _a, _b;

    for (i = 0; i < PIXEL; i++)
    {
        x = (double)(i * SIZE) / PIXEL - (SIZE / 2.0);

        for (j = 0; j < PIXEL; j++)
        {
            y = (double)(j * SIZE) / PIXEL - (SIZE / 2.0);

            for (k = 0; k < C_COUNT; k++)
            {
                _a = x;
                _b = y;
                x = _a * _a - _b * _b + first_x;
                y = 2 * _a * _b + first_y;

                if (x * x + y * y > 4.0)
                {
                    // ピクセルを描画（集合外の点を描画）
                    my_mlx_pixel_put(data, i, j, 255 - k);  // 255は白色
                    break;
                }
                else if (k == C_COUNT - 1)
                {
                    // ピクセルを描画（集合内の点を描画）
                    my_mlx_pixel_put(data, i, j, 0);  // 0は黒色
                }
            }
        }
    }
}

// void	julia(t_data *data, double first_x, double first_y)
// {
// 	int i;
// 	int j;
// 	int k;
// 	double x;
// 	double y;
// 	double _a;
// 	double _b;

// 	x = 0;
// 	y = 0;
// 	i = 0;
// 	j = 0;
// 	for (i = 0; PIXEL > i; i++)
// 	{
// 		x = (double)((double)i * (double)(SIZE)) / (double)PIXEL
// 			- ((double)((double)SIZE / 2.0));

// 		for (j = 0; PIXEL > j; j++)
// 		{
// 			y = (double)((double)j * (double)SIZE) / (double)PIXEL
// 				- (double)((double)SIZE / 2.0);
// 				printf("x:%f y:%f\n", x, y);
// 			for (k = 0; C_COUNT > k; k++)
// 			{
// 				_a = x;
// 				_b = y;
// 				x = pow(_a, 2) - pow(_b, 2) + first_x;
// 				y = (double)2 * _a * _b + first_y;

// 				if (pow(x, 2) + pow(y, 2) > 4.0)
// 					my_mlx_pixel_put(data, i, j, 255);
// 			}
// 		}
// 	}
// }