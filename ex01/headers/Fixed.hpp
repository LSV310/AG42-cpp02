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

		Fixed&			operator=(const Fixed& Fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed);
