#include <iostream>

int fibo ( int n )
{
    
	if ( n == 1 or n ==2)
	{
	    
	    return 1;
	    
	}else{
	
	return fibo( n - 1 ) + fibo( n - 2 );
	
	    
	}
}

int main ( void )
{
	int n(0);
	std::cout << "Informe o limite para o calculo da Sequencia de Fibonacci\n";
	std::cin >> n;
	std::cout << "Limite: f(" << n << ")" << std::endl;

	for ( auto i(0) ; i < n ; i++ )
	{
        fibo(n);
		std::cout << fibo(i+1) << std::endl;
	}

	return ( 0 );
}
