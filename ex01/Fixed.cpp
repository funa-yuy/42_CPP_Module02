#include"Fixed.hpp"

// コンストラクタ ---------------------------------------------
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
	*this = c;
}

/*
 * コピー代入演算子 (A copy assignment operator overload.)
 */
Fixed &Fixed::operator=(const Fixed& c) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &c)
		this->fixed_point_ = c.fixed_point_;
	return (*this);
}

/*
 * デストラクタ
 */
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/*
 * コンストラクタ
 * 整数値を固定小数点値に変換してfixed_point_に入れる。
*/
Fixed::Fixed(const int value) : fixed_point_(value) {
	std::cout << "Int constructor called" << std::endl;
	fixed_point_ = value << fractional_bits_;
}

/*
 * コンストラクタ
 * 浮動小数点を固定小数点値に変換してfixed_point_に入れる。
*/
Fixed::Fixed(const float value) : fixed_point_(value) {
	std::cout << "Float constructor called" << std::endl;
	fixed_point_ = roundf(value * (1 << fractional_bits_));
}

/*
 * 固定小数点値の生の値を返す
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

/*
 * 固定小数点値を整数値に変換する
 */
int Fixed::toInt( void ) const {
	int	value;

	value = fixed_point_ >> fractional_bits_;
	return (value);
}

/*
 * 固定小数点値を浮動小数点値に変換する
 */
float Fixed::toFloat( void ) const {
	float	value;

	value = static_cast<float>(fixed_point_) / (1 << fractional_bits_);
	return (value);
}



// ストリーム挿入演算子のオーバーロード ---------------------------------------------
/*
 * 固定小数点数を浮動小数点にして出力する
 */
std::ostream &operator<<(std::ostream &os, const Fixed &value) {
	os << value.toFloat();
	return os;
}

