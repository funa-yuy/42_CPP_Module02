#include"Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

// int main() {
// 	std::cout << std::boolalpha;  // bool を true/false 表示にする

// 	Fixed a(5.5f);
// 	Fixed b(2);

// 	std::cout << "a = " << a << ", b = " << b << "\n\n";

// 	std::cout << "比較演算子" << std::endl;
// 	std::cout << "a > b: "  << (a > b)  << "\n";
// 	std::cout << "a < b: "  << (a < b)  << "\n";
// 	std::cout << "a >= b: " << (a >= b) << "\n";
// 	std::cout << "a <= b: " << (a <= b) << "\n";
// 	std::cout << "a == b: " << (a == b) << "\n";
// 	std::cout << "a != b: " << (a != b) << "\n\n";

// 	std::cout << "算術演算子" << std::endl;
// 	std::cout << "a + b = " << (a + b) << "\n";
// 	std::cout << "a - b = " << (a - b) << "\n";
// 	std::cout << "a * b = " << (a * b) << "\n";
// 	std::cout << "a / b = " << (a / b) << "\n\n";

// 	std::cout << "インクリ／デクリメント" << std::endl;
// 	Fixed c(a);
// 	std::cout << "c = "   << c   << "\n";
// 	std::cout << "++c = " << ++c << "\n";
// 	std::cout << "c++ = " <<  c++ << "\n";
// 	std::cout << "c = "   <<  c   << "\n";
// 	std::cout << "--c = " << --c << "\n";
// 	std::cout << "c-- = " <<  c-- << "\n";
// 	std::cout << "c = "   <<  c   << "\n\n";

// 	std::cout << "static min/max (non-const)" << std::endl;
// 	std::cout << "min(a,b) = " << Fixed::min(a, b) << "\n";
// 	std::cout << "max(a,b) = " << Fixed::max(a, b) << "\n\n";

// 	std::cout << "static min/max (const)" << std::endl;
// 	const Fixed ca(3.3f), cb(4.4f);
// 	std::cout << "min(ca,cb) = " << Fixed::min(ca, cb) << "\n";
// 	std::cout << "max(ca,cb) = " << Fixed::max(ca, cb) << "\n";

// 	return 0;
// }
