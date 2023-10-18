typedef struct {
    int r;
    int g;
    int b;
} RGBColor;

int roundToByte(float value) {
    return (int)(value * 255);
}

RGBColor hsv2rgb(float H, float S, float V) {
    float h = H / 360;
    float s = S / 100;
    float v = V / 100;
    
    int i = (int)(h * 6);
    float f = h * 6 - i;
    float p = v * (1 - s);
    float q = v * (1 - f * s);
    float t = v * (1 - (1 - f) * s);

    float r, g, b;

    if (i == 0) {
        r = v;
        g = t;
        b = p;
    } else if (i == 1) {
        r = q;
        g = v;
        b = p;
    } else if (i == 2) {
        r = p;
        g = v;
        b = t;
    } else if (i == 3) {
        r = p;
        g = q;
        b = v;
    } else if (i == 4) {
        r = t;
        g = p;
        b = v;
    } else {
        r = v;
        g = p;
        b = q;
    }

    RGBColor color;
    color.r = roundToByte(r);
    color.g = roundToByte(g);
    color.b = roundToByte(b);
    return color;
}

#include <stdio.h>
int main()
{
	
}