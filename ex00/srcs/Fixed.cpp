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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_number = raw;
	return ;
}
