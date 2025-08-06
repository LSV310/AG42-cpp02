#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

void test(const Point &a, const Point &b, const Point &c, const Point &point) {
	std::cout << "Test point " << point << ": ";
	if (bsp(a, b, c, point))
		std::cout << "Touché ✅" << std::endl;
	else
		std::cout << "Coulé ❌" << std::endl;
}

int main(void)
{
	const Point a(5, 8);
	const Point b(8, 15);
	const Point c(15, 5);

	// Cas dans le triangle
	test(a, b, c, Point(8, 12.1));    // ✅ dedans
	test(a, b, c, Point(10, 11));     // ✅ dedans
	test(a, b, c, Point(7, 10));      // ✅ dedans
	test(a, b, c, Point(9, 9));       // ✅ dedans
	test(a, b, c, Point(10, 8));      // ✅ dedans
	test(a, b, c, Point(11, 10));     // ✅ dedans
	test(a, b, c, Point(8.5, 11));    // ✅ dedans
	test(a, b, c, Point(6, 9));       // ✅ dedans
	test(a, b, c, Point(12, 8));      // ✅ dedans
	test(a, b, c, Point(9, 12));      // ✅ dedans
	test(a, b, c, Point(13, 7));      // ✅ dedans
	test(a, b, c, Point(10.5, 9.5));  // ✅ dedans

	// Cas en dehors du triangle
	test(a, b, c, Point(16, 16));      // ❌ dehors
	test(a, b, c, Point(3, 3));        // ❌ dehors
	test(a, b, c, Point(5, 15));       // ❌ dehors

	// Cas sur une arête
	test(a, b, c, Point(6.5, 11.5));   // ⚠️ sur [a,b]
	test(a, b, c, Point(11.5, 10));    // ⚠️ sur [b,c]
	test(a, b, c, Point(10, 6.5));     // ⚠️ sur [c,a]

	// Cas sur un sommet
	test(a, b, c, a);                  // ⚠️ sommet a
	test(a, b, c, b);                  // ⚠️ sommet b
	test(a, b, c, c);                  // ⚠️ sommet c

	return 0;
}
