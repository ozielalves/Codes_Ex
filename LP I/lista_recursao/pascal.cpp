#include <iostream>

int pascal( int n, int k )
{
	if(k == 0 or n == k) return 1; 
	// else if( k == 1 or (k + 1) = n) return n;
	else return (pascal( n-1, k-1) + pascal( n-1,k));	
}


int main( void )
{}
/*	int n, k;
	
	std::cout << " Type de pyramid's height: " << std::endl;
	std::cin >> n;

	std::cout << "

	return 0;	
}
*/

