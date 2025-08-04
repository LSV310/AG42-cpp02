#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_number = 0;
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& Fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &Fixed)
		*this = Fixed;
	return ;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->_number = number << Fixed::_decimal_bits;
	return ;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->_number = roundf(number * (1 << this->_decimal_bits)); // (1 << n) == 2^n
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator=(const Fixed& Fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_number = Fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_number);
}

void	Fixed::setRawBits(int const raw)
{
	this->_number = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_number / (1 << this->_decimal_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_number / (1 << this->_decimal_bits));
}

std::ostream&	operator<<(std::ostream &stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return (stream);
}
