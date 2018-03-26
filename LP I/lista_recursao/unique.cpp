#include <iostream>
#include <algorithm>

int *find( int *first, int *last, int *value )
{
	if(*first == *value) return first;
	else if(*first != *value) return find( (first += 1), last, value );
	else return last;	
}

int *unique( int *first, int *last )
{
	int *found = find( first += 1, last, first);
	if( found != last )
	{	
		 *found = *(found += 1);
	}
	else if(first == last) return last;
	else return unique( (found += 1), last );		
}
/*
int main ( void )
{
	int V[] = {1,2,3,4,4,5,5,6,6,7,8,7};
	int *result = (unique( std::begin(V), std::end(V) ));  
	for( auto *i = std::begin(V); i < result; i++)
	{
		std::cout << *(i) << std::endl;
	}
	return 0;	
}
*/
