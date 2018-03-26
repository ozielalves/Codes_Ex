#include <iostream>

int greatest_common_divisor( int x, int y )
{
	if( x%y == 0 )	return y;

	return greatest_common_divisor( y, x%y);
}

int main( void )
{
	int x;
	int y;

	std::cout << "Type the two numbers to know their GCD: " <<std::endl;
	std::cin >> x;
	std::cin >> y;
	std::cout << "Their GCD is: " << greatest_common_divisor( x, y ) << std::endl;

	return 0;
}
