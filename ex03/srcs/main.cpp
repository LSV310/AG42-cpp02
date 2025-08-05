#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	const Point	a(5, 8);
	const Point	b(8, 15);
	const Point	c(15, 5);
	const Point	point(8, 12.1);

	std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
	if (bsp(a, b, c, point))
		std::cout << "Touché" << std::endl;
	else
		std::cout << "Coulé" << std::endl;
	return 0;
}
