#include <iostream> // std::cout , std::endl
#include <iterator> // std::begin (), std::end ()

using namespace std;

const int * min( const int *first , const int * last )
{
	const int *offset;
    int index = 1;
    
	while( first != last )
	{
		if(*first < *(first + index))
		{
			offset = first;
		}
		else continue;
		
		first += 1;
		index += 1;
	}
	return offset; 
}

int main ( void ) 
{
	int A[] = {1, 2, -3, -4, 5, -6};
	
	// Deveria imprimir -6.
	auto result = min ( begin (A), end(A) );
	std::cout << * result << std::endl ;
	
	// Deveria imprimir -4
	result = min ( begin (A)+1 , begin (A )+5 );
	std::cout << * result << std::endl ;

return 0;
