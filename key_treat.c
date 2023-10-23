/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_treat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:13:07 by ksho              #+#    #+#             */
/*   Updated: 2023/10/23 18:21:47 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_windows *param)
{
	(void)param;
	printf("window closed\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int	change_color(int keycode, t_windows *param)
{
	if (!param)
		exit(EXIT_FAILURE);
	else if (keycode == LeftArrow)
	{
		if (param->what_sets == 'j')
			about_julia(param);
		else if (param->what_sets == 'm')
			about_mandel(param);
	}
	else if (keycode == 53)
		close_window(param);
	return (0);
}

int	close_window_with_x(t_windows *param)
{
	ft_printf("window closed\n");
	mlx_destroy_image(param->mlx, param->img);
	mlx_destroy_window(param->mlx, param->win);
	exit(EXIT_SUCCESS);
}

int	zoom_in_out(int keycode, int x, int y, t_windows *param)
{
	static int	num;

	param->mouse_x = x;
	param->mouse_x = y;
	if (keycode == 4)
		num += 1;
	else if (keycode == 5)
		num -= 1;
	param->zoom_in_out = num;
	if (param->what_sets == 'm')
		zoom_mandel(param);
	else if (param->what_sets == 'j')
		zoom_julia(param);
	return (0);
}
