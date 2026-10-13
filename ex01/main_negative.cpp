#include "Fixed.hpp"

static void	check( const std::string& label, const Fixed& f, float expectedFloat, int expectedInt )
{
	float	gotFloat = f.toFloat();
	int		gotInt = f.toInt();
	bool	ok = (gotFloat == expectedFloat && gotInt == expectedInt);

	std::cout << (ok ? "[OK] " : "[KO] ") << label
			  << " -> toFloat: " << gotFloat << " (attendu " << expectedFloat << ")"
			  << ", toInt: " << gotInt << " (attendu " << expectedInt << ")"
			  << std::endl;
}

int main( void )
{
	std::cout << "===== Constructeur int negatif =====" << std::endl;
	Fixed const a( -1 );
	Fixed const b( -10 );
	Fixed const c( -8388608 );	// plus petit int representable avec 8 bits fractionnaires

	std::cout << "\n===== Constructeur float negatif =====" << std::endl;
	Fixed const d( -42.42f );
	Fixed const e( -0.5f );
	Fixed const f( -1.5f );
	Fixed const g( -0.00390625f );	// -1/256, plus petite valeur negative
	Fixed const h( -0.001f );		// trop petit, arrondi a 0

	std::cout << "\n===== Copie / assignation de negatifs =====" << std::endl;
	Fixed const i( d );
	Fixed j;
	j = Fixed( -1234.4321f );

	std::cout << "\n===== Affichage via operator<< =====" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "f is " << f << std::endl;
	std::cout << "g is " << g << std::endl;
	std::cout << "h is " << h << std::endl;
	std::cout << "i is " << i << std::endl;
	std::cout << "j is " << j << std::endl;

	std::cout << "\n===== Verifications =====" << std::endl;
	// Note : toInt() utilise /, qui tronque vers 0 pour les negatifs
	// (-0.5 -> 0, -42.42 -> -42), comme un cast (int) sur un float.
	check("Fixed(-1)", a, -1.0f, -1);
	check("Fixed(-10)", b, -10.0f, -10);
	check("Fixed(-8388608)", c, -8388608.0f, -8388608);
	check("Fixed(-42.42f)", d, -42.421875f, -42);
	check("Fixed(-0.5f)", e, -0.5f, 0);
	check("Fixed(-1.5f)", f, -1.5f, -1);
	check("Fixed(-1/256)", g, -0.00390625f, 0);
	check("Fixed(-0.001f)", h, 0.0f, 0);
	check("copie de d", i, -42.421875f, -42);
	check("j = Fixed(-1234.4321f)", j, -1234.43359375f, -1234);

	std::cout << "\n===== Raw bits =====" << std::endl;
	int	rawA = a.getRawBits();
	int	rawE = e.getRawBits();
	std::cout << "raw(-1)    = " << rawA << " (attendu -256)" << std::endl;
	std::cout << "raw(-0.5f) = " << rawE << " (attendu -128)" << std::endl;

	std::cout << std::endl;
	return (0);
}
