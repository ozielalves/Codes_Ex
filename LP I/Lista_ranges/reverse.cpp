#include <iostream> // std::cout , std::endl
#include <iterator> // std::begin (), std::end ()
#include <algorithm> // std::swap ()

using namespace std;

void reverse( int * first , int * last )
{
	for((auto *) i = first, (auto *) j = last; first = last; i++, j--)
	{
		std::swap( *i, *j);
	}
}


int main () {
int A[] = { 1, 2, 3, 4, 5 };

// aplicar reverse sobre todo o vetor .
reverse ( begin (A), end (A) );

// O comando abaixo deveria imprimir A com o conteudo 5, 4, 3, 2, 1
for( auto i( begin (A) ) ; i != end(A) ; ++i )
cout << *i << " ";
cout << std::endl ;

// aplicar reverse sobre parte do vetor .
reverse ( begin (A)+1 , begin (A)+4 );

// O comando abaixo deveria imprimir A com o conteudo 5, 2, 3, 4, 1
for( auto i( begin (A) ) ; i != end(A) ; ++i )
cout << *i << " ";
cout << std::endl ;

return 0;
}
