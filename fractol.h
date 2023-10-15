#ifndef FRACTOL_H
# define FRACTOL_H
# define SIZE 8
# define PIXEL 600
# define C_COUNT 100

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
# include <stdio.h>

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
void		mandel(t_data *data);
void		julia(t_data *data, double first_x, double first_y);
#endif
