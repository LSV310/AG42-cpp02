#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	Fixed c(5);
	Fixed d(5.0f);
	std::cout << (c == d) << std::endl;
	std::cout << (c != d) << std::endl;
	std::cout << (a != d) << std::endl;
	std::cout << (c < d) << std::endl;
	std::cout << (a < d) << std::endl;
	std::cout << (c >= d) << std::endl;
	std::cout << (c - d + 10) << std::endl;
	c = Fixed(5);
	std::cout << (c * d) << std::endl;
	return 0;
}
