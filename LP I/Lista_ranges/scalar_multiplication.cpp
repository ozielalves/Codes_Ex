#include <iostream> // std::cout , std::endl
#include <iterator> // std::begin (), std::end ()

void scalar_multiplication ( int * first , int * last , int scalar )
{
	for( auto *i = (int *)first; i <= left; i++)
	{
		*i = (*i) * scalar;
	}
}

int main () 
{
	int Vet [] = {1 , 2 , -3 , -4 , 5 , -6};
	scalar_multiplication ( begin ( Vet ) , end ( Vet ) , 3 );
	// O vetor resultante seria :
	// { 3 , 6 , -9 , -12 , 15 , -18 }.
	return 0;
}