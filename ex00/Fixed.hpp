#ifndef FIXED_CLASS
#define FIXED_CLASS

#include <iostream>
#include <string>

class Fixed
{
private:
	int              _fixedPointNumber;
	static const int _FractionalBitNumber = 8;

public:
	Fixed();
	~Fixed();

	Fixed( const Fixed& src);
	Fixed&  operator = (const Fixed& src);
	int     getRawBits( void ) const;
	void    setRawBits( int const raw );
};

#endif