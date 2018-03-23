#include <iostream> // std :: cout , std :: endl
#include <iterator> // std :: begin () , std :: end () , std :: cbegin () , std :: cend ()

using namespace std ;

int dot_product ( const int * a_first , const int * a_last , const int * b_first, const int * b_last )
{
	int dot_product = 0
	for( auto i(0), i < a_last - a_first ; i++)
	{
		dot_product = dot_product +  (*(a_first + i) * *(b_first +i));
	}

return dot_product;
}

int main () {
// Desejamos multiplicar a =[1 , 3 , -5] · b =[4 , -2 , -1].
int Vet [] = {1 , 3 , -5 , 4 , -2 , -1 }; // Os dois vetores armazenados no mesmo arranjo .
auto result = dot_product ( begin( Vet ) , begin( Vet )+3 , // Vetor a
begin ( Vet )+3 ); // Vetor b
// O comando abaixo deveria imprimir 3 , se correto .
cout << " >>> O resultado ´e: " << result << std::endl ;
// [1 ,3 , -5]·[4 , -2 , -1] = (1)(4)+(3)( -2)+( -5)( -1)
// = 4 - 6 + 5
// = 3.
return 0;
}
