#ifndef FIXED_HPP
# define FIXED_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include<iostream>
#include<string>
#include <cstdlib>
#include<cmath>

// ------------------------------------------------
// class
// ------------------------------------------------

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed& c);
		Fixed& operator=(const Fixed& c);
		~Fixed();
		Fixed(const int value);
		Fixed(const float value);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt( void ) const;
		float toFloat( void ) const;

		/* 「左辺」を指す引数は lhs（left-hand side）、「右辺」を指す引数をは rhs(right-hand side)。 */
		/* 比較演算子 : 数値の比較 */
		bool operator<(const Fixed& rhs) const;
		bool operator>(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;

		/* 算術演算子 数値の計算 */
		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;

		/* インクリメント, デクリメント */
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		/* min, max */
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);

	private:
		int fixed_point_;//固定小数点数値を格納する整数。
		static const int fractional_bits_ = 8;//小数点以下のビット数を格納し、値は常に整数リテラル8になります。
};

// ------------------------------------------------
// function
// ------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Fixed &rhs);

#endif
