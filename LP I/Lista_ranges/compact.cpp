#include <iostream>

int *compact( int *first, int *last )
{
	int counter_neg = 0;
	
	// Primeiro faremos uma contagem de quantos elementos irão restar
	for( int *i = first ; i < last ; i++ )
	{
		
		if( *i < 0 ) counter_neg++;	
	
	}

	int *buf = ( int * ) calloc ( counter_neg , sizeof(int) );
	
	// Agora podemos preencher a lista com os elementos válidos
	for( auto i(0) , *j = first ; j < last ; j++ )
	{
		if( *j < 0 )
		{
			buf[i++] = *j;
		} 
	}

	return buf;
}

