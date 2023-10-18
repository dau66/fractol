/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:45:36 by ksho              #+#    #+#             */
/*   Updated: 2023/10/18 21:59:49 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fractol.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}



int	main(void)
{

	void	*mlx;
	void	*mlx_win;
	t_data	img;

	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, PIXEL, PIXEL, "Hello world!");
	img.img = mlx_new_image(mlx, PIXEL, PIXEL);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	// mandel(&img);
	julia(&img,0.1,0.4);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

// int main()
// {
//     double re;
//     double im;
//     int i = 0;
//     int j = 0;
//     int k = 0;
//     double a = 0;
//     double b = 0;
//     double _a = 0;
//     double _b = 0;
    
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, PIXEL,  PIXEL, "Tutorial Window - Draw Pixel");
//     while(i < PIXEL)
//     {
//         re = (i * SIZE) / (PIXEL / 2) - (SIZE / 2);
//         while(j < PIXEL)
//         {
//             im = (j * SIZE) / (PIXEL / 2)  - (SIZE / 2);
//             a = 0;
//             b = 0;
//             while(k < C_COUNT)
//             {
//                 _a = a * a - b * b + re;
//                 _b = 2 * a * b+im;
//                 a = _a;
//                 b = _b;
//                 if(a * a + b * b > 4)
//                 {
//                     mlx_pixel_put(mlx, win, i , j, 0xFFFFFF);
//                     break;
//                 }
//                 k ++;
//             }
//             k = 0;
//             j ++;
//         }
//             j = 0;
//             i ++;
//     }
//    mlx_string_put(mlx, win, 320,320, 0,"abcderf");
//     mlx_loop(mlx);
// }