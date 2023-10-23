/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:45:36 by ksho              #+#    #+#             */
/*   Updated: 2023/10/24 05:28:25 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q mlx-test");
// }

static void	julia_setting(t_windows *param, double x, double y)
{
	param->julia_x = x;
	param->julia_y = y;
}

static t_windows	window_setting(t_windows window)
{
	window.mlx = mlx_init();
	if (window.mlx == NULL)
		exit(EXIT_FAILURE);
	window.win = mlx_new_window(window.mlx, PIXEL, PIXEL, "Hello world!");
	if (window.win == NULL)
		exit(EXIT_FAILURE);
	window.img = mlx_new_image(window.mlx, PIXEL, PIXEL);
	if (window.img == NULL)
		exit(EXIT_FAILURE);
	window.addr = mlx_get_data_addr(window.img, &window.bits_per_pixel,
			&window.line_length, &window.endian);
	return (window);
}

int	main(int argc, char **argv)
{
	t_windows	window;

	window.mouse_x = 0;
	window.mouse_y = 0;
	window = window_setting(window);
	if (argc == 2 && argv[1][0] == 'm')
		mandel(&window);
	else if (argc == 4 && argv[1][0] == 'j')
	{
		julia_setting(&window, ft_atod(argv[2]), ft_atod(argv[3]));
		julia(&window, window.julia_x, window.julia_y);
	}
	else
		error_output();
	mlx_put_image_to_window(window.mlx, window.win, window.img, 0, 0);
	mlx_hook(window.win, KeyPress, KeyPressMask, change_color, &window);
	mlx_hook(window.win, DestroyNotify, StructureNotifyMask, close_window,
		NULL);
	mlx_mouse_hook(window.win, zoom_in_out, &window);
	mlx_loop(window.mlx);
}

// i

// //return NULL
// window.win = mlx_new_window(window.mlx, PIXEL, PIXEL, "Hello world!");
// //return NULL
// window.img = mlx_new_image(window.mlx, PIXEL, PIXEL);
// // return NULL
// window.addr = mlx_get_data_addr(window.img, &window.bits_per_pixel,
// 		&window.line_length, &window.endian);