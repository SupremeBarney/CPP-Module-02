#include "Point.hpp"

int main( void )
{
	// Affiche true / false au lieu de 1 / 0
	std::cout << std::boolalpha;

	// Triangle rectangle en C : A(0,0), B(10,10), C(10,0)
	Point	a(0.0f, 0.0f);
	Point	b(10.0f, 10.0f);
	Point	c(10.0f, 0.0f);

	std::cout << "(7,3)   dedans  attendu true  : " << bsp(a, b, c, Point(7.0f, 3.0f)) << std::endl;
	std::cout << "(3,7)   dehors  attendu false : " << bsp(a, b, c, Point(3.0f, 7.0f)) << std::endl;
	std::cout << "(0,0)   sommet  attendu false : " << bsp(a, b, c, Point(0.0f, 0.0f)) << std::endl;
	std::cout << "(5,5)   arete   attendu false : " << bsp(a, b, c, Point(5.0f, 5.0f)) << std::endl;

	// Meme triangle translate de (-5,-5) : A(-5,-5), B(5,5), C(5,-5)
	std::cout << "(2,-2)  dedans  attendu true  : " << bsp(Point(-5.0f, -5.0f), Point(5.0f, 5.0f), Point(5.0f, -5.0f), Point(2.0f, -2.0f)) << std::endl;

	return (0);
}
