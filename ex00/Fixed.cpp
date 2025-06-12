#include"Fixed.hpp"

/* デフォルトコンストラクタ */
Fixed::Fixed() : fixed_point_(0) {
	std::cout << "Default constructor called" << std::endl;
}

/* コピーコンストラクタ */
Fixed::Fixed(const Fixed& c) : fixed_point_(c.fixed_point_) {
	std::cout << "Copy constructor called" << std::endl;
}

/* コピー代入演算子のオーバーロード */
Fixed &Fixed::operator=(const Fixed& c) {
	std::cout << "Copy assignment operator calle" << std::endl;
	if (this != &c)
		this->fixed_point_ = c.fixed_point_;
	return (*this);
}

/* デストラクタ */
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed_point_);
}

void Fixed::setRawBits(int const raw) {
	fixed_point_ = raw;
}
