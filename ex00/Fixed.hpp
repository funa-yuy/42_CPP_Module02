#ifndef FIXED_HPP
# define FIXED_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include<iostream>
#include<string>
#include <cstdlib>

// ------------------------------------------------
// class
// ------------------------------------------------

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed& c);
		Fixed& operator=(const Fixed& c);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int fixed_point_;//固定小数点数値を格納する整数。
		static const int fractional_bits_ = 8;//小数点以下のビット数を格納し、値は常に整数リテラル8になります。
};

// ------------------------------------------------
// function
// ------------------------------------------------


#endif
