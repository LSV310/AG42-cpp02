#pragma once

#include <iostream>

class Fixed {

	private:
		int					_number;
		static const int	_decimal_bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& Fixed);
		~Fixed(void);

		Fixed& operator=(const Fixed& Fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};
