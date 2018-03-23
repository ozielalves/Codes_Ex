#include <iostream> // std :: cout , std :: endl
#include <iterator> // std :: begin () , std :: end () , std :: cbegin () , std :: cend ()

using namespace std ;

int * copy( const int * first , const int * last , int * d_first )
{
	while( first != last )
	{
		auto i = 0;
		(int*)d_first + i = ((int*)first + i);
	}

	return d_first;
}

int main () 
{
	int A [] = { 1 , 2 , 3 , 4 , 5 }; // Vetor " fonte ".
	int B [] = { 0 , 0 , 0 }; // Vetor " destino ".
	// Copiar elementos 2 , 3 , e 4 para o in´ıcio de B.
	auto b_last = copy ( begin ( A )+1 , begin ( A )+4 , begin ( B ) );
	// O comando abaixo deveria imprimir B com o conte´udo 2 , 3 , 4.
	for ( auto i ( begin (B) ) ; i != b_last ; ++ i )
	{
	cout << * i << " ";
	cout << std :: endl ;
	return 0;
	}
}