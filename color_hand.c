/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_hand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:49:05 by ksho              #+#    #+#             */
/*   Updated: 2023/10/23 18:28:43 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_RGBColor	set_rgb_1(t_HSVColor hsv, int int_x6_hsv)
{
	double		f;
	double		p;
	double		q;
	double		t;
	t_RGBColor	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	f = hsv.h * 6 - int_x6_hsv;
	p = hsv.v * (1 - hsv.s);
	q = hsv.v * (1 - f * hsv.s);
	t = hsv.v * (1 - (1 - f) * hsv.s);
	if (int_x6_hsv % 6 == 0)
		color = set_rgb(hsv.v * 255, t * 255, p * 255);
	else if (int_x6_hsv % 6 == 1)
		color = set_rgb(q * 255, hsv.v * 255, p * 255);
	return (color);
}

static t_RGBColor	set_rgb_2(t_HSVColor hsv, int int_x6_hsv)
{
	double		f;
	double		p;
	double		q;
	double		t;
	t_RGBColor	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	f = hsv.h * 6 - int_x6_hsv;
	p = hsv.v * (1 - hsv.s);
	q = hsv.v * (1 - f * hsv.s);
	t = hsv.v * (1 - (1 - f) * hsv.s);
	if (int_x6_hsv % 6 == 2)
		color = set_rgb(p * 255, hsv.v * 255, t * 255);
	else if (int_x6_hsv % 6 == 3)
		color = set_rgb(p * 255, q * 255, hsv.v * 255);
	return (color);
}

static t_RGBColor	set_rgb_3(t_HSVColor hsv, int int_x6_hsv)
{
	double		f;
	double		p;
	double		q;
	double		t;
	t_RGBColor	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	f = hsv.h * 6 - int_x6_hsv;
	p = hsv.v * (1 - hsv.s);
	q = hsv.v * (1 - f * hsv.s);
	t = hsv.v * (1 - (1 - f) * hsv.s);
	if (int_x6_hsv % 6 == 4)
		color = set_rgb(t * 255, p * 255, hsv.v * 255);
	else if (int_x6_hsv % 6 == 5)
		color = set_rgb(hsv.v * 255, p * 255, q * 255);
	return (color);
}

static t_HSVColor	set_hsv(double H, double S, double V)
{
	t_HSVColor	hsv;

	hsv.h = H / 360;
	hsv.s = S / 100;
	hsv.v = V / 100;
	return (hsv);
}

t_RGBColor	hsv2rgb(double H, double S, double V)
{
	int			i;
	t_RGBColor	color;
	t_HSVColor	hsv;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	hsv = set_hsv(H, S, V);
	i = floor(hsv.h * 6);
	if ((i % 6 == 0) || (i % 6 == 1))
		color = set_rgb_1(hsv, i);
	else if ((i % 6 == 2) || (i % 6 == 3))
		color = set_rgb_2(hsv, i);
	else if ((i % 6 == 4) || (i % 6 == 5))
		color = set_rgb_3(hsv, i);
	return (color);
}

// int	main(void)
// {
// 	t_RGBColor hsv;

// 	hsv = hsv2rgb(300, 50, 50);
// 	printf("%d %d %d\n", (int)hsv.r, (int)hsv.g, (int)hsv.b);
// }