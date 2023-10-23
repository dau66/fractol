/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:25:33 by ksho              #+#    #+#             */
/*   Updated: 2023/10/23 18:25:39 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define SIZE 4
# define PIXEL 600
# define C_COUNT 100
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <float.h>
# include <math.h>
# include <stdio.h>

typedef struct HSVColor
{
	double	h;
	double	s;
	double	v;
}			t_HSVColor;

typedef struct RGBColor
{
	double	r;
	double	g;
	double	b;
}			t_RGBColor;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		change_color;
	double	julia_x;
	double	julia_y;
	char	what_sets;
	int		zoom_in_out;
	int		mouse_x;
	int		mouse_y;
}			t_windows;

enum		e_events
{
	KeyPress = 2,
	KeyRelease = 3,
	LeaveNotify = 8,
	GraphicsExpose = 13,
	NoExpose = 14,
	DestroyNotify = 17,
};

enum		e_keycode
{
	LeftArrow = 123,
	RightArrow = 124,
	Escape = 53,
};

enum		e_event_masks
{
	KeyPressMask = (1L << 0),
	LeaveWindowMask = (1L << 5),
	StructureNotifyMask = (1L << 17),
};

void		my_mlx_pixel_put(t_windows *data, int x, int y, int color);
int			hsv_to_rgb(double h, double s, double v);
void		mandel(t_windows *data);
void		julia(t_windows *data, double first_x, double first_y);
t_RGBColor	hsv2rgb(double H, double S, double V);
int			change_color(int keycode, t_windows *param);
void		window_free(t_windows **param);
int			close_window(t_windows *param);
int			close_window_with_x(t_windows *param);
double		ft_atod(char *nptr);
void		error_output(void);
void		about_julia(t_windows *param);
void		about_mandel(t_windows *param);
int			zoom_in_out(int keycode, int x, int y, t_windows *param);
void		zoom_mandel(t_windows *param);
void		zoom_julia(t_windows *param);
t_RGBColor	set_rgb(int r, int g, int b);

#endif
