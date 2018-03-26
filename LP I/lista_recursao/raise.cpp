#include <iostream>

int raise_to_power( int n, int k )
{
	if( k == 0) return 1;
	else k--;
	
	return n * raise_to_power( n, k );	
}

int main ( void )
{
	int n;
	int k;
	std::cout << "Type the two number to calculate he pow: " << std:: endl;
	std::cin >> n;
	std::cin >> k;

	std::cout << "The pow is "<< raise_to_power( n, k ) << std::endl;
	return 0;
}
