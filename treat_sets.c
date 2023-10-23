/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_sets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:43:40 by ksho              #+#    #+#             */
/*   Updated: 2023/10/23 18:26:43 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	about_julia(t_windows *param)
{
	static int	change_color;

	change_color += 10;
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_image(param->mlx, param->img);
	param->img = mlx_new_image(param->mlx, PIXEL, PIXEL);
	param->change_color = change_color;
	julia(param, param->julia_x, param->julia_y);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}

void	about_mandel(t_windows *param)
{
	static int	change_color;

	change_color += 10;
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_image(param->mlx, param->img);
	param->img = mlx_new_image(param->mlx, PIXEL, PIXEL);
	param->change_color = change_color;
	mandel(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}

void	zoom_mandel(t_windows *param)
{
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_image(param->mlx, param->img);
	param->img = mlx_new_image(param->mlx, PIXEL, PIXEL);
	mandel(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}

void	zoom_julia(t_windows *param)
{
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_image(param->mlx, param->img);
	param->img = mlx_new_image(param->mlx, PIXEL, PIXEL);
	julia(param, param->julia_x, param->julia_y);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}
