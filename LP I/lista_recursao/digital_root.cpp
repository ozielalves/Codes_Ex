#include <iostream>

/*
int digit_sum( int n )
{
     if( n < 10) return n;
 
     return digit_sum(n/10) + n%10;
}
*/

int digital_root( int n )
{
	if(n < 10) return n;
	
	return digital_root( n/10 + n%10);		
}

int main ( void )
{
	int n;
    std::cout << "Type the number: " << std:: endl;
    std::cin >> n;

    std::cout << "The elements digital_root is: " << digital_root( n ) << std::endl;

    return 0;
}

