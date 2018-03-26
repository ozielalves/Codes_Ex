#include <iostream>

int cannonballs;

int cannonball( int height)
{	
	if ( height == 1 ) return 1;	
	
	return (height * height) + cannonball( height - 1);	 
}

int main ( void )
{
	int height;
	std::cout << "Type the cannonball pyramid height: " << std:: endl;
	std::cin >> height ;

	std::cout << "The pyramid will have "<< cannonball(height) << " cannonballs" << std::endl;
	return 0;
}
