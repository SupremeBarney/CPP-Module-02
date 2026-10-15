#ifndef FIXED_CLASS
#define FIXED_CLASS

#include <iostream>
#include <cmath>
#include <cstdlib>

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

	Fixed&			operator=(const Fixed& src);
	int				operator>(const Fixed& src) const;
	int				operator<(const Fixed& src) const;
	int				operator>=(const Fixed& src) const;
	int				operator<=(const Fixed& src) const;
	int				operator!=(const Fixed& src) const;
	Fixed			operator+(const Fixed& src) const;
	Fixed			operator-(const Fixed& src) const;
	Fixed			operator*(const Fixed& src) const;
	Fixed			operator/(const Fixed& src) const;
	int				operator==(const Fixed& src) const;
	Fixed&			operator++();
	Fixed			operator++( int );
	Fixed&			operator--();
	Fixed			operator--( int );

	static Fixed&	min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

};
	
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif