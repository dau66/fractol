#ifndef FRACTOL_H
# define FRACTOL_H
# define SIZE 4
# define PIXEL 600
# define C_COUNT 500

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct HSVColor
{
	double	h;
	double	s;
	double	v;
}			HSVColor;

typedef struct RGBColor
{
	double	r;
	double	g;
	double	b;
}			RGBColor;

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
# include <stdio.h>

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			hsv_to_rgb(double h, double s, double v);
void		mandel(t_data *data);
void		julia(t_data *data, double first_x, double first_y);
RGBColor	hsv2rgb(double H, double S, double V);

#endif
