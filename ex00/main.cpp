#include"Fixed.hpp"

int main( void ) {
	Fixed a;// デフォルトコンストラクタ
	Fixed b( a );// コピーコンストラクタ
	Fixed c;

	c = b;//コピー代入演算子

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
