#include"Fixed.hpp"

/*
 * デフォルトコンストラクタ
 */
Fixed::Fixed() : fixed_point_(0) {}

/*
 * コピーコンストラクタ
 */
Fixed::Fixed(const Fixed& c) {
	*this = c;
}

/*
 * コピー代入演算子 (A copy assignment operator overload.)
 */
Fixed &Fixed::operator=(const Fixed& c) {
	if (this != &c)
		this->fixed_point_ = c.fixed_point_;
	return (*this);
}

/*
 * デストラクタ
 */
Fixed::~Fixed() {}

/*
 * コンストラクタ
 * 整数値を固定小数点値に変換してfixed_point_に入れる。
*/
Fixed::Fixed(const int value) : fixed_point_(value) {
	fixed_point_ = value << fractional_bits_;
}

/*
 * コンストラクタ
 * 浮動小数点を固定小数点値に変換してfixed_point_に入れる。
*/
Fixed::Fixed(const float value) : fixed_point_(value) {
	fixed_point_ = roundf(value * (1 << fractional_bits_));
}

/*
 * 固定小数点値の生の値を返す
 */
int Fixed::getRawBits(void) const{
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

// min, max ---------------------------------------------

/*
 * 固定小数点数への参照を持つ2つのパラメータとして受け取り、
 * 最小のものへの参照を返します。
 */
Fixed&	Fixed::min(Fixed& a, Fixed& b) { 					//ex02
	if (a.fixed_point_ <= b.fixed_point_)
		return (a);
	else
		return (b);
}

/*
 * 定数(const)の固定小数点数への参照を持つ2つのパラメータとして受け取り、
 * 最小のものへの参照を返します。
 * 引数では、const オブジェクトも non-const オブジェクトも受け取れる
 */
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) { //ex02
	if (a.fixed_point_ <= b.fixed_point_)
		return (a);
	else
		return (b);
}

/*
 * 固定小数点数への参照を持つ2つのパラメータとして受け取り、
 * 最大のものへの参照を返します。
 */
Fixed&	Fixed::max(Fixed& a, Fixed& b) { 					//ex02
	if (a.fixed_point_ >= b.fixed_point_)
		return (a);
	else
		return (b);
}

/*
 * 定数(const)の固定小数点数への参照を持つ2つのパラメータとして受け取り、
 * 最大のものへの参照を返します。
 * 引数では、const オブジェクトも non-const オブジェクトも受け取れる
 */
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) { //ex02
	if (a.fixed_point_ >= b.fixed_point_)
		return (a);
	else
		return (b);
}

// 比較演算子のオーバーロード ---------------------------------------------

bool Fixed::operator<(const Fixed& rhs) const {				//ex02
	return (this->fixed_point_ < rhs.fixed_point_);
}

bool Fixed::operator>(const Fixed& rhs) const {				//ex02
	return (this->fixed_point_ > rhs.fixed_point_);
}

bool Fixed::operator>=(const Fixed& rhs) const {			//ex02
	return (this->fixed_point_ >= rhs.fixed_point_);
}

bool Fixed::operator<=(const Fixed& rhs) const {			//ex02
	return (this->fixed_point_ <= rhs.fixed_point_);
}

bool Fixed::operator==(const Fixed& rhs) const {			//ex02
	return (this->fixed_point_ == rhs.fixed_point_);
}

bool Fixed::operator!=(const Fixed& rhs) const {			//ex02
	return (this->fixed_point_ != rhs.fixed_point_);
}

// 算術演算子 数値の計算 ---------------------------------------------

Fixed Fixed::operator+(const Fixed& rhs) const {					 //ex02
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed& rhs) const {					//ex02
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed& rhs) const {					//ex02
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed& rhs) const {					//ex02
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

// インクリメント, デクリメント ---------------------------------------------

Fixed& Fixed::operator++() {								//ex02
	this->fixed_point_++;
	return (*this);
}

/*
 * 前置インクリメントと区別するために、引数にintを受け取る
 */
Fixed Fixed::operator++(int) {								//ex02
	Fixed	tmp;

	tmp = *this;
	this->fixed_point_++;
	return (tmp);
}

/*
 * 前置デクリメントと区別するために、引数にintを受け取る
 */
Fixed& Fixed::operator--() {								//ex02
	this->fixed_point_--;
	return (*this);
}

Fixed Fixed::operator--(int) {								//ex02
	Fixed	tmp;

	tmp = *this;
	this->fixed_point_--;
	return (tmp);
}

//  ストリーム挿入演算子のオーバーロード ---------------------------------------------

/*
 * 固定小数点数を浮動小数点にして出力する
 */
std::ostream &operator<<(std::ostream &os, const Fixed &value) {
	os << value.toFloat();
	return os;
}
