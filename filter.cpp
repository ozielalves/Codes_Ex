#include <iostream>

int main ( void )
{

	int vet[10];
	int *inicio;
	int *fim;

	std::cout << "Digite a lista de numeros a ser filtrada:\n";
	std::cin >> vet[10];

	//inicio = vet[0];
	//fim = vet[10];

	for ( auto i(0) ; i < 11 ; i++ )
	{	
		inicio = vet[i];
		if ( *inicio < 0 or *inicio == 0)
		{

			delete *inicio;

		} else {
		
			inicio++;
		
		}
	}

	for ( auto i(0) ; i >= 0 ; i-- )
	{	
		fim = vet[i];
		if ( *fim < 0 or *fim == 0)
		{

			delete *fim;

		} else {
			

			fim--;
		
		}
	}

	std::cout << "O vetor filtrado e: " << std::endl;
	
	for ( auto i(0) ; i < 11 ; i++ )
	{

		std::cout << vet[i] " " << std::endl;

	}

	return (0);
}	