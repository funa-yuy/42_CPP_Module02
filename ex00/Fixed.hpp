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
		Fixed();//固定小数点数値を 0 に初期化するデフォルトコンストラクタ(A default constructor )。
		Fixed(const Fixed& c);//コピーコンストラクタ。(A copy constructor.)
		Fixed& operator=(const Fixed& c);//コピー代入演算子のオーバーロード。(A copy assignment operator overload.)
		~Fixed();	//デストラクタ(A destructor)
		int getRawBits(void) const;//固定小数点値の生の値を返します。 //constをつけることで、この関数内ではメンバ変数の変更ができなくなる。constメンバ関数とも呼ばれる
		void setRawBits(int const raw);//固定小数点数の生の値を設定します。

	private:
		int fixed_point_;
		static const int fractional_bits_;
};

// ------------------------------------------------
// function
// ------------------------------------------------


#endif
