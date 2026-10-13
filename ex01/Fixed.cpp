#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed& src ) : _fixedPointNumber(src._fixedPointNumber)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator= ( const Fixed& src )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	_fixedPointNumber = src._fixedPointNumber;
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointNumber);
}

void    Fixed::setRawBits( int const raw )
{
	_fixedPointNumber = raw;
}

Fixed::Fixed( const int num ) : _fixedPointNumber(num * (1 << _fractionalBitNumber))
{
	std::cout << "Int constructor called" << std::endl;
}

int	Fixed::toInt( void ) const
{
	return (_fixedPointNumber / (1 << _fractionalBitNumber));
}

Fixed::Fixed( const float fnum ) : _fixedPointNumber(roundf(fnum * (1 << _fractionalBitNumber)))
{
	std::cout << "Float constructor called" << std::endl;
}

float	Fixed::toFloat( void ) const
{
	return ((float)_fixedPointNumber / (1 << _fractionalBitNumber));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	return (os << obj.toFloat());
}