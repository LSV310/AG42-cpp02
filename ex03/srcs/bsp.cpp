#include "Point.hpp"

float	sign(Point const a, Point const b, Point const c)
{
	Fixed	result = (a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (a.getY() - c.getY());
	return (result.toFloat());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	d1, d2, d3;

	std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	return (d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0);
}
