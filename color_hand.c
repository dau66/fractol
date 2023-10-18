/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_hand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:49:05 by ksho              #+#    #+#             */
/*   Updated: 2023/10/18 21:08:36 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static RGBColor	set_rgb_1(HSVColor hsv, int int_x6_hsv)
{
	double		f;
	double		p;
	double		q;
	double		t;
	RGBColor	color;

	f = hsv.h * 6 - int_x6_hsv;
	p = hsv.v * (1 - hsv.s);
	q = hsv.v * (1 - f * hsv.s);
	t = hsv.v * (1 - (1 - f) * hsv.s);
	if (int_x6_hsv % 6 == 0)
	{
		color.r = hsv.v;
		color.g = t;
		color.b = p;
	}
	else if (int_x6_hsv % 6 == 1)
	{
		color.r = q;
		color.g = hsv.v;
		color.b = p;
	}
	color.r = color.r * 255;
	color.g = color.g * 255;
	color.b = color.b * 255;
	return (color);
}

static RGBColor	set_rgb_2(HSVColor hsv, int int_x6_hsv)
{
	double		f;
	double		p;
	double		q;
	double		t;
	RGBColor	color;

	f = hsv.h * 6 - int_x6_hsv;
	p = hsv.v * (1 - hsv.s);
	q = hsv.v * (1 - f * hsv.s);
	t = hsv.v * (1 - (1 - f) * hsv.s);
	if (int_x6_hsv % 6 == 2)
	{
		color.r = p;
		color.g = hsv.v;
		color.b = t;
	}
	else if (int_x6_hsv % 6 == 3)
	{
		color.r = p;
		color.g = q;
		color.b = hsv.v;
	}
	color.r = color.r * 255;
	color.g = color.g * 255;
	color.b = color.b * 255;
	return (color);
}

static RGBColor	set_rgb_3(HSVColor hsv, int int_x6_hsv)
{
	double		f;
	double		p;
	double		q;
	double		t;
	RGBColor	color;
	
	f = hsv.h * 6 - int_x6_hsv;
	p = hsv.v * (1 - hsv.s);
	q = hsv.v * (1 - f * hsv.s);
	t = hsv.v * (1 - (1 - f) * hsv.s);
	if (int_x6_hsv % 6 == 4)
	{
		color.r = t;
		color.g = p;
		color.b = hsv.v;
	}
	else if (int_x6_hsv % 6 == 5)
	{
		color.r = hsv.v;
		color.g = p;
		color.b = q;
	}
	color.r = floor(color.r * 255);
	color.g = floor(color.g * 255);
	color.b = floor(color.b * 255);
	return (color);
}

static HSVColor	set_hsv(double H, double S, double V)
{
	HSVColor	hsv;

	hsv.h = H / 360;
	hsv.s = S / 100;
	hsv.v = V / 100;
	return (hsv);
}

RGBColor	hsv2rgb(double H, double S, double V)
{
	int			i;
	RGBColor	color;
	HSVColor	hsv;

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
// 	RGBColor hsv;

// 	hsv = hsv2rgb(300, 50, 50);
// 	printf("%d %d %d\n", (int)hsv.r, (int)hsv.g, (int)hsv.b);
// }