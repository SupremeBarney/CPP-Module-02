#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointNumber(0)
{
}

Fixed::~Fixed( void )
{
}

Fixed::Fixed( const Fixed& src ) : _fixedPointNumber(src._fixedPointNumber)
{
}

Fixed& Fixed::operator= ( const Fixed& src )
{
	if (this == &src)
		return (*this);
	_fixedPointNumber = src._fixedPointNumber;
	return (*this);
}

int Fixed::operator> ( const Fixed& src ) const
{
	if (_fixedPointNumber > src._fixedPointNumber)
		return (1);
	return (0);
}

int Fixed::operator< ( const Fixed& src ) const
{
	if (_fixedPointNumber < src._fixedPointNumber)
		return (1);
	return (0);
}

int Fixed::operator>= ( const Fixed& src ) const
{
	if (_fixedPointNumber >= src._fixedPointNumber)
		return (1);
	return (0);
}

int Fixed::operator<= ( const Fixed& src ) const
{
	if (_fixedPointNumber <= src._fixedPointNumber)
		return (1);
	return (0);
}

int Fixed::operator!= ( const Fixed& src ) const
{
	if (_fixedPointNumber != src._fixedPointNumber)
		return (1);
	return (0);
}

int Fixed::operator== ( const Fixed& src ) const
{
	if (_fixedPointNumber == src._fixedPointNumber)
		return (1);
	return (0);
}

Fixed Fixed::operator+ ( const Fixed& src ) const
{
	Fixed	res;
	res.setRawBits(_fixedPointNumber + src.getRawBits());
	return (res);
}

Fixed Fixed::operator- ( const Fixed& src ) const
{
	Fixed	res;
	res.setRawBits(_fixedPointNumber - src.getRawBits());
	return (res);
}

Fixed Fixed::operator* ( const Fixed& src ) const
{
	Fixed	res;
	res.setRawBits((long)_fixedPointNumber * src.getRawBits() / (1 << _fractionalBitNumber));
	return (res);
}

Fixed Fixed::operator/ ( const Fixed& src ) const
{
	Fixed	res;
	if (!src.getRawBits())
		exit (EXIT_FAILURE);
	res.setRawBits((long)_fixedPointNumber * (1 << _fractionalBitNumber) / src.getRawBits());
	return (res);
}

Fixed& Fixed::operator++ ()
{
	_fixedPointNumber++;
	return (*this);
}

Fixed Fixed::operator++ ( int )
{
	Fixed	old((*this));

	operator++();
	return (old);
}

Fixed& Fixed::operator-- ()
{
	_fixedPointNumber--;
	return (*this);
}

Fixed Fixed::operator-- ( int )
{
	Fixed	old(*this);

	operator--();
	return (old);
}

int Fixed::getRawBits( void ) const
{
	return (_fixedPointNumber);
}

void    Fixed::setRawBits( int const raw )
{
	_fixedPointNumber = raw;
}

Fixed::Fixed( const int num ) : _fixedPointNumber(num * (1 << _fractionalBitNumber))
{
}

int	Fixed::toInt( void ) const
{
	return (_fixedPointNumber / (1 << _fractionalBitNumber));
}

Fixed::Fixed( const float fnum ) : _fixedPointNumber(roundf(fnum * (1 << _fractionalBitNumber)))
{
}

float	Fixed::toFloat( void ) const
{
	return ((float)_fixedPointNumber / (1 << _fractionalBitNumber));
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const  Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const  Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	return (os << obj.toFloat());
}