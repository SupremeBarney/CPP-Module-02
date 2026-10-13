#ifndef FIXED_CLASS
#define FIXED_CLASS

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int              _fixedPointNumber;
	static const int _fractionalBitNumber = 8; 

public:
	Fixed();
	Fixed( const int num );
	Fixed( const float fnum);
	~Fixed();

	Fixed( const Fixed& src);
	Fixed&  operator = (const Fixed& src);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};
	
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif