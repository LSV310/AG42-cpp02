#pragma once

#include <iostream>
#include "Fixed.hpp"

class Point {

	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point(void);
		Point(float x, float y);
		Point(const Fixed x, const Fixed y);
		Point(const Point& Point);
		~Point(void);

		Point&	operator=(const Point& Point);

		Fixed	getX(void) const;
		Fixed	getY(void) const;

};

std::ostream&	operator<<(std::ostream& stream, const Point& point);
bool			bsp(Point const a, Point const b, Point const c, Point const point);
