#include <iostrem>

int main ( void )
{

	int m, n;;

	//Enquanto houver para processar, soma...
	while ( std::cin >> m >> n )
	{

		auto acc(0); //acumula a soma de serie solicitada
		for ( auto i(0) ; i < n ; ++i )
			acc += (m+i);

		std:: cout <<acc << std::endl;
	}

	return 0;
}