#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point( const float init_x, const float init_y) : _x( init_x ), _y( init_y )
{
}

Point::Point( const Point& cpy ) : _x(cpy._x), _y(cpy._y)
{
}

Point&	Point::operator=( const Point& cpy )
{
	(void)cpy;
	return (*this);
}

Point::~Point()
{

}

Fixed	Point::GetX() const
{
	return (_x);
}

Fixed	Point::GetY() const
{
	return (_y);
}