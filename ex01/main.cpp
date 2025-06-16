#include"Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );//コピーコンストラクタの中で、コピー代入演算子が呼ばれる

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl; //coutは、デフォルトでは有効数字6桁までしか出力しない
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl; //固定小数点への変換時に、小数点以下を丸めることで誤差が生じる
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
