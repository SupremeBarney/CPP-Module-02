#ifndef POINT_CLASS
#define POINT_CLASS

#include "Fixed.hpp"

class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;
public:
	Point();
	Point( const float init_x, const float init_y );
	Point( const Point& cpy );
	Point&	operator=( const Point& cpy );
	~Point();

	Fixed	GetX() const;
	Fixed	GetY() const;
};
	
bool	bsp( Point const a, Point const b, Point const c, Point const point );

#endif