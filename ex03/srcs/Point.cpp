#include "Point.hpp"

Point::Point(void): _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(float x, float y): _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(Fixed const x, Fixed const y): _x(x), _y(y) {}

Point::Point(const Point& Point): _x(Point.getX()), _y(Point.getY()) {}

Point::~Point(void)
{
	return ;
}

Point&	Point::operator=(const Point& point)
{
	(void)point;
	return (*this);
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}

std::ostream&	operator<<(std::ostream &stream, const Point& point)
{
	stream << "(" << point.getX() << ", " << point.getY() << ")";
	return (stream);
}
