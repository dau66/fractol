#include "fractol.h"

__attribute__((destructor)) static void destructor()
{
	system("leaks -q a.out");
}

void	rere(double first_x, double first_y)
{
	int		i;
	int		j;
	int		k;
	double	x;
	double	y;
	double	_a;
	double	_b;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	_a = 0;
	for (i = 0; PIXEL > i; i++)
	{
		x = (double)((double)i * (double)(SIZE)) / (double)PIXEL
			- ((double)((double)SIZE / 2.0));
		for (j = 0; PIXEL > j; j++)
		{
			y = (double)((double)j * (double)SIZE) / (double)PIXEL
				- (double)((double)SIZE / 2.0);
			printf("x:%f y:%f\n", x, y);
			if(i == 6)
			  break ;
			for (k = 0; 1 > k; k++)
			{
				_a = x;
				_b = y;
				x = pow(_a, 2) - pow(_b, 2) + first_x;
				y = (double)2 * _a * _b + first_y;
				if (pow(x, 2) + pow(y, 2) > 4)
					break ;
			}
		}
		// printf("x:%f y:%f\n", x, y);
	}
}

int	main(void)
{
	double x, y;

	x = 2;
	y = 2;
	rere(x, y);
}