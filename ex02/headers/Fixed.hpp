#pragma once

#include <iostream>
#include <cmath>

class Fixed {

	private:
		int					_number;
		static const int	_decimal_bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& Fixed);
		Fixed(const int number);
		Fixed(const float number);
		~Fixed(void);

		Fixed&	operator=(const Fixed& Fixed);
		bool	operator==(const Fixed& Fixed) const;
		bool	operator>(const Fixed& Fixed) const;
		bool	operator<(const Fixed& Fixed) const;
		bool	operator>=(const Fixed& Fixed) const;
		bool	operator<=(const Fixed& Fixed) const;
		bool	operator!=(const Fixed& Fixed) const;
		Fixed	operator+(const Fixed& fixed) const;
		Fixed	operator-(const Fixed& fixed) const;
		Fixed	operator*(const Fixed& fixed) const;
		Fixed	operator/(const Fixed& fixed) const;
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed&		min(Fixed &Fixed1, Fixed &Fixed2);
		static const Fixed&	min(const Fixed &Fixed1, const Fixed &Fixed2);
		static Fixed&		max(Fixed &Fixed1, Fixed &Fixed2);
		static const Fixed&	max(const Fixed &Fixed1, const Fixed &Fixed2);

};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed);
