#include <iostream>

int main ( void )
{

	int A[19];   
	int B[19];
	std::cout << "Informe os 20 numeros:\n";
// Indices para percorrer o vetor
	auto i(0);
    auto j(0);
    
	for ( i = 0 ; i < 20 ; i++ ) // Entrada dos 20 numeros
	{
	
	    std::cin >> B[i];
	
	}    

	std::cout << "Os numeros são: \n";


	for ( i = 0 ; i < 20 ; i++) // Saida dos 20 numeros
	{
	    
	    std::cout << " " << B[i] << "  \n\n";

	}

// Trocando elementos de ordem impar do Vetor A	
	for ( i = 0, j = 19 ; i < 20 and j >=0 ; i++, j--)
	{
	    if ( B[i] % 2 != 0 )
	    {
	    
	    B[i] = B[i + 1];
	        
	    }    
	}
	
	std::cout << "O novo vetor e: \n";


	for ( i = 0 ; i < 20 ; i++) // Saida do novo vetor
	{
	    
	    std::cout << " " << B[i] << "  \n\n";

	}
	

	return (0);

}
