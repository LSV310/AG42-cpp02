#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_number = 0;
	return ;
}

Fixed::Fixed(const Fixed& Fixed)
{
	if (this != &Fixed)
		*this = Fixed;
	return ;
}

Fixed::Fixed(const int number)
{
	this->_number = number << Fixed::_decimal_bits;
	return ;
}

Fixed::Fixed(const float number)
{
	this->_number = roundf(number * (1 << this->_decimal_bits)); // (1 << n) == 2^n
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed&	Fixed::operator=(const Fixed& Fixed)
{
	this->_number = Fixed.getRawBits();
	return (*this);
}

bool	Fixed::operator==(const Fixed& Fixed) const
{
	return (this->_number == Fixed._number);
}

bool	Fixed::operator<(const Fixed& Fixed) const
{
	return (this->_number < Fixed._number);
}

bool	Fixed::operator>(const Fixed& Fixed) const
{
	return (this->_number > Fixed._number);
}

bool	Fixed::operator>=(const Fixed& Fixed) const
{
	return (this->_number >= Fixed._number);
}

bool	Fixed::operator<=(const Fixed& Fixed) const
{
	return (this->_number <= Fixed._number);
}

bool	Fixed::operator!=(const Fixed& Fixed) const
{
	return (this->_number != Fixed._number);
}

Fixed	Fixed::operator+(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& fixed) const
{
	return (Fixed((this->toFloat() - fixed.toFloat())));
}

Fixed	Fixed::operator*(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& fixed) const
{
	if (fixed.toFloat() == 0.0f)
		std::cout << "\e[1;31mDon't kill me please\e[0m" << std::endl;
	return (Fixed((this->toFloat() / fixed.toFloat())));
}

Fixed&	Fixed::operator++(void)
{
	this->_number++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;

	this->_number++;
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	this->_number--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;

	this->_number--;
	return (temp);
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

Fixed&	Fixed::min(Fixed &Fixed1, Fixed &Fixed2)
{
	if (Fixed1 <= Fixed2)
		return (Fixed1);
	return (Fixed2);
}

const Fixed&	Fixed::min(const Fixed &Fixed1, const Fixed &Fixed2)
{
	if (Fixed1 <= Fixed2)
		return (Fixed1);
	return (Fixed2);
}

Fixed&	Fixed::max(Fixed &Fixed1, Fixed &Fixed2)
{
	if (Fixed1 >= Fixed2)
		return (Fixed1);
	return (Fixed2);
}

const Fixed&	Fixed::max(const Fixed &Fixed1, const Fixed &Fixed2)
{
	if (Fixed1 >= Fixed2)
		return (Fixed1);
	return (Fixed2);
}

std::ostream&	operator<<(std::ostream &stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return (stream);
}
