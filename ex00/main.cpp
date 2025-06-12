#include"Fixed.hpp"

int main( void ) {
	Fixed a;// デフォルトコンストラクタでオブジェクト作成
	Fixed b( a );// コピーコンストラクタでオブジェクト作成
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
