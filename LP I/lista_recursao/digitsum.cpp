#include <iostream>

int digit_sum( int n )
{
	if( n < 10) return n;

	return digit_sum(n/10) + n%10; 	
} 

int main ( void )
{
	int n;
	std::cout << "Type the number to sum: " << std:: endl;
	std::cin >> n;

	std::cout << "The elements sum is: " << digit_sum( n ) << std::endl;
	
	return 0;
}
