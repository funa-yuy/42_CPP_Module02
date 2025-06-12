#include"Fixed.hpp"

/*
 * デフォルトコンストラクタ
 * 固定小数点数値を 0 に初期化するデフォルトコンストラクタ(A default constructor )
 */
Fixed::Fixed() : fixed_point_(0) {
	std::cout << "Default constructor called" << std::endl;
}

/*
 * コピーコンストラクタ
 */
Fixed::Fixed(const Fixed& c) {
	std::cout << "Copy constructor called" << std::endl;
	fixed_point_ = c.getRawBits();
}

/*
 * コピー代入演算子 (A copy assignment operator overload.)
 */
Fixed &Fixed::operator=(const Fixed& c) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &c)
		this->fixed_point_ = c.getRawBits();
	return (*this);
}

/*
 * デストラクタ
 */
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/*
 * 固定小数点値の生の値を返す
 * constをつけることで、この関数内ではメンバ変数の変更ができなくなる。
 * constメンバ関数とも呼ばれる
 */
int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed_point_);
}

/*
 * 固定小数点数の生の値を設定する
 */
void Fixed::setRawBits(int const raw) {
	fixed_point_ = raw;
}
