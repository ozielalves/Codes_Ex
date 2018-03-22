#include <iostream>

int main ( void )
{

	int vet[19]; //  
	std::cout << "Informe os 20 numeros:\n";

// Declaração das vaiaveis para percorrer o vetor
	auto r(0);
	auto i(0);
	
// Entrada dos 20 numeros	
	for ( r = 0 ; r <= 19 ; r++) 
	
	    std::cin >> vet[r];
	
	}    
	
	std::cout << "Os numeros são: \n";


// Saida dos 20 numeros
	for ( i = 0 ; i < 20 ; i++) 
	{
	    
	    std::cout << " " << vet[i] << "  \n\n";

	}

	auto min = vet[19];
	auto posicao(0);

// Encontrando o valor minimo 	
	for ( r = 0 ; r < 20 ; r++ ) {

		if( vet[r] < min ) {
			min = vet[r];
			posicao = r;
		}
			
	}

	std::cout << "O menor valor informado e: " << min << "\n";
	std::cout << "E a sua posicao e: " << posicao << std::endl;
	
	return ( 0 );

}
