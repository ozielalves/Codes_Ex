#include <iostream> // std::cout , std::endl
#include <iterator> // std::begin (), std::end ()

void negate ( int * first , int * last )
{
	while(first != last)
	{
		*first = *first * (-1);
		first++;
	}
}

int main () {
int Vet [] = {1, 2, -3, -4, 5, -6};

	// Nega todo o vetor .
	negate ( std::begin( Vet), std::end( Vet) );

	// Nega do 3ro ate o ultimo elemento do vetor .
	negate ( std::begin ( Vet )+2 , std::end( Vet) );

	// Nega apenas o 4to elemento do vetor .
	negate ( std::begin( Vet )+3 , std::begin ( Vet )+4 );

	return 0;
}