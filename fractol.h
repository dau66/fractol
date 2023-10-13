#ifndef FRACTOL_H
# define FRACTOL_H
# define SIZE 4
# define PIXEL 800
# define C_COUNT 50

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
int			create_trgb(int r, int g, int b);
void		m_fractol(t_data *data);

#endif
