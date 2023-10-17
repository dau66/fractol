#include <math.h>
#include <stdio.h>

typedef struct RGBColor
{
	int		r;
	int		g;
	int		b;
}			RGBColor;

static 

RGBColor	hsv2rgb(float H, float S, float V)
{
	float		h;
	float		s;
	float		v;
	int			i;
	float		f;
	float		p;
	float		q;
	float		t;
	RGBColor	color;

	float r, g, b;
	h = H / 360;
	s = S / 100;
	v = V / 100;
	i = floor(h * 6);
	f = h * 6 - i;
	p = v * (1 - s);
	q = v * (1 - f * s);
	t = v * (1 - (1 - f) * s);
	switch (i % 6)
	{
	case 0:
		r = v, g = t, b = p;
		break ;
	case 1:
		r = q, g = v, b = p;
		break ;
	case 2:
		r = p, g = v, b = t;
		break ;
	case 3:
		r = p, g = q, b = v;
		break ;
	case 4:
		r = t, g = p, b = v;
		break ;
	case 5:
		r = v, g = p, b = q;
		break ;
	}
	color.r = r * 255;
	color.g = g * 255;
	color.b = b * 255;
	return (color);
}

int	main(void)
{
	RGBColor hsv;

	hsv = hsv2rgb(300, 50, 50);
	printf("%d %d %d\n", hsv.r, hsv.g, hsv.b);
}