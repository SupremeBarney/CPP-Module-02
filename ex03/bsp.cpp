#include "Point.hpp"

static Fixed	w1( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	res = (a.GetX() * (c.GetY() - a.GetY()) + (point.GetY() - a.GetY()) * (c.GetX() - a.GetX()) - point.GetX() * (c.GetY() - a.GetY())) / ((b.GetY() - a.GetY()) * (c.GetX() - a.GetX()) - (b.GetX() - a.GetX()) * (c.GetY() - a.GetY()));
	return (res);
}

static Fixed	w2( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	res = (point.GetY() - a.GetY() - w1(a, b, c, point) * (b.GetY() - a.GetY())) / (c.GetY() - a.GetY());
	return (res);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	if (((b.GetY() - a.GetY()) * (c.GetX() - a.GetX()) - (b.GetX() - a.GetX()) * (c.GetY() - a.GetY()) == 0))
		return (false);

	if (a.GetY() == c.GetY())
	{
		if (a.GetY() == b.GetY())
			return (false);
		return(bsp(a, c, b, point));
	}
	Fixed	m1(w1(a, b, c, point));
	Fixed	m2(w2(a, b, c, point));

	if (m1 > 0 && m2 > 0 && (m1 + m2) < 1)
		return (true);
	return (false);
}
