/**!
 *  Program usado na avaliação de LP1, 2017.1
 *  @date 11 de abrill de 2017
 */

#include <iostream>  // cout, endl
#include <iomanip>   // setw
#include <iterator>  // distance
#include <cstdlib>   // memset, memcmp, memcpy
#include <cassert>   // assert()



// ================================================================================

namespace prova
{
    // Tipos basicos utiizados pelas funções.
    using byte = unsigned char;
    using Compare = int(const void*, const void*);
    using UnaryPredicate = bool(const void*);

    // Questão 1
    bool eh_particionada( const void * first, const void * last, size_t size, UnaryPredicate *p )
	{    
        // Casting sendo feito diretamente para  byte
        // byte * f = static_cast < byte * > (first);        
        // byte * l = static_cast < byte * > (last);

        byte * f = (byte *) first; 
        byte * l = (byte *) last; 

        bool flag = false; // Nosso indicador - Se o predicado deixa de ser atendido ou não

        while(f != (l - size)) // Vai até o penultimo elemento do vetor
        {
            if( p(f) ) // Se o predicado for atendido
            {
                // Não é particionada (O predicado ja havia sido descumprido anteriormente)
                if( flag == true) return false; 
            }
            else 
            {
                flag = true;
            }
            
            f += size;
        }
        return true;
    }  

    // Questão 2-a
    const void * limite_inferior( const void *first, const void *last,
            size_t size, const void * value, Compare *cmp )
   {
        byte *f = (byte *) first;
        byte *l = (byte *) last;
        byte *m;

        if(cmp(f, value) != -1) return first;

        f += size;

        while(f != l){
            m = f + ((std::distance(f, l) / size) / 2) * size;

            if(cmp((void *)(m), value) != -1){
                if(cmp((void *)(m - size), value) == -1) return (void *) m;
                else l = m;
            }else{
                f = m + size;
            }
        }
        return last;
    }
    // Questão 2-b
    const void * limite_superior( const void *first, const void *last,
            size_t size, const void * value, Compare *cmp )
    {
        byte *f = (byte *) first;
        byte *l = (byte *) last;
        byte *m;

        if(cmp(f, value) == 1) return first;

        f += size;

        while(f != l){
            m = f + ((std::distance(f, l) / size) / 2) * size;

            if(cmp((void *)(m), value) == 1){
                if(cmp((void *)(m - size), value) != 1) return (void *) m;
                else l = m;
            }else{
                f = m + size;
            }
        }
        return last;
    }
    // Questão 3
    void * remove( const void *first, const void *last, const void *first_r,
               const void *last_r, size_t size )
    {
		byte * f = (byte *) first;
		byte * f_r = (byte *) first_r;
		byte * l = (byte *) last;
		byte * l_r = (byte *) last_r;

		byte * new_l = f;

		while( f < l )
		{
			if( f >= f_r and l <= l_r )	f += size;
			else
			{
				std::copy(f, f + size, new_l); // copy[(range), (destino)], similar to memcpy
				f += size;
				new_l += size;
			}

		}
        return (void *) last;
	}

    // Questão 4
    bool contem( const void *first1, const void *last1, const void *first2,
            const void *last2, size_t size, Compare *cmp )
    {
        byte *f1 = (byte *) first1;
        byte *l1 = (byte *) last1;
        byte *f2 = (byte *) first2;
        byte *l2 = (byte *) last2;

        bool flag = false;

        while( f2 < l2 ){
            while( cmp( (void *)f2, (void *) f1) == -1){ // ou seja: Enquanto os elementos
                if( f1 == l1 ) return false;             // do intervalo forem menores
                f1 += size; 
            }
            f2 += size;
        }

        return true;
    }

    // Questão 5
    void * remove_repetidos( const void *first, const void *last, const void *value,
            size_t size, Compare *cmp )
    {
        byte *f = (byte *) first;
        byte *l = (byte *) last;

        byte *new_l = f;
        
        while(f < l){
            if( cmp((void *)f,value) != 0){
                std::copy(f, f+size, new_l);
                new_l += size;
            } f += size;  

        }return (void*) new_l;
    }
} // namespace prova


// ================================================================================
// CLIENT CODE
// ================================================================================

/*int void_int( void *first )
{
    int * f
}*/

bool eh_impar( const void *a )
{
    return *(int *)a % 2 != 0;   //faltou dizer que era ponteiro pra inteiro 
}

bool acima_20( const void *a )
{
    // TODO: seu código vai aqui
    return false; // Stub, substituir...
}

int compare_ints( const void * a, const void * b )
{
    int a_i = *(int *) a;
    int b_i = *(int *) b;

    if( a_i < b_i) return -1;
    if( a_i == b_i) return 0;
    else return 1;     
}



int main( )
{
    size_t score = 0;
    size_t total = 65; // Pontos das 2 primeiras questões.
    std::cout << ">>> Voce inicia a prova com " << score << " pontos (de " << total << ").\n\n";

    // ================================================================================
    // Questao 1 - teste: vetor está particionado
    // ================================================================================
    {
        std::cout << ">>> Q1-a: testando a funcao eh_particionada()\n";

        int A[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

        // Verificando se o vetor estah particionado com os impares na frente dos pares.
        auto result = prova::eh_particionada( std::begin(A), std::end(A), sizeof(int), eh_impar );
        if ( result == false )
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
        else
        {
            score += 10;
            std::cout << "    Sua resposta estah correta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";

    // ================================================================================
    // Questao 1 - teste:  vetor NÃO está particionado
    // ================================================================================
    {
        std::cout << ">>> Q1-b: testando a funcao eh_particionada()\n";

        int A[] = { 21, 41, 54, 38, 6, 5, 21, 4, 1, -3 };

        // Verificando se o vetor estah particionado com os valores acima de 20 na frente.
        auto result = prova::eh_particionada( std::begin(A), std::end(A), sizeof(int), acima_20 );

        if ( result == true )
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
        else
        {
            score += 10;
            std::cout << "    Sua resposta estah correta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";

    // ================================================================================
    // Questao 2
    // ================================================================================
    {
        std::cout << ">>> Q2-a: testando a funcao limite_inferior(): limite inferior no meio\n";

        int A[] = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };
        auto target(4);

        // buscando o limite inferior
        auto li = (int *) prova::limite_inferior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( *li == 4 and std::distance(std::begin(A), li) == 7 )
        {
            score += 5;
            std::cout << "    Sua resposta estah correta!\n";
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


    {
        std::cout << ">>> Q2-b: testando a funcao limite_inferior(): valor ausente mas limite inferior no intervalo\n";

        int A[] = { 1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 5, 5, 6 };
        auto target(4);

        // buscando o limite inferior
        auto li = (int *) prova::limite_inferior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( *li == 5 and std::distance(std::begin(A), li) == 10)
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


    {
        std::cout << ">>> Q2-c: testando a funcao limite_inferior(): limite inferior fora do intervalo\n";

        int A[] = { 1, 1, 2, 3, 3, 3 };
        auto target(5);

        // buscando o limite inferior
        auto li = (int *) prova::limite_inferior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( li == std::end(A) )
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


    {
        std::cout << ">>> Q2-d: testando a funcao limite_inferior(): limite inferior no inicio\n";

        int A[] = { 1, 1, 2, 3, 3, 3 };
        auto target(1);

        // buscando o limite inferior
        auto li = (int *) prova::limite_inferior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( li == std::begin(A) )
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


    {
        std::cout << ">>> Q2-e: testando a funcao limite_superior(): valor presente, limite inferior no meio do vetror.\n";

        int A[] = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };
        auto target(4);

        // buscando o limite inferior
        auto li = (int *) prova::limite_superior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( *li == 5 and std::distance(std::begin(A), li) == 10 )
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


    {
        std::cout << ">>> Q2-f: testando a funcao limite_superior(): valor ausente, limite superior presente.\n";

        int A[] = { 1, 1, 2, 3, 3, 3, 3, 5, 5, 6 };
        auto target(4);

        // buscando o limite inferior
        auto li = (int *) prova::limite_superior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( *li == 5 and std::distance(std::begin(A), li) == 7 )
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


    {
        std::cout << ">>> Q2-g: testando a funcao limite_superior(): valor ausente, limite superior fora do intervalo.\n";

        int A[] = { 1, 1, 2, 3, 3, 3, 3, 5, 5, 6 };
        auto target(7);

        // buscando o limite inferior
        auto li = (int *) prova::limite_superior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( li == std::end(A) )
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


    {
        std::cout << ">>> Q2-h: testando a funcao limite_superior(): valor no inicio\n";

        int A[] = { 1, 1, 2, 3, 3, 3, 3, 5, 5, 6 };
        auto target(1);

        // buscando o limite inferior
        auto li = (int *) prova::limite_superior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( *li == 2 and std::distance( std::begin(A), li ) == 2 )
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";

    {
        std::cout << ">>> Q2-i: testando a funcao limite_superior(): valor menor que início do intervalo.\n";

        int A[] = { 1, 1, 2, 3, 3, 3, 3, 5, 5, 6 };
        auto target(0);

        // buscando o limite inferior
        auto li = (int *) prova::limite_superior( std::begin(A), std::end(A), sizeof(int),
                &target, compare_ints );

        if ( *li == 1 and li == std::begin(A) )
        {
            std::cout << "    Sua resposta estah correta!\n";
            score += 5;
        }
        else
        {
            std::cout << "    Sua resposta estah incorreta!\n";
        }
    }
    std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";

    // ================================================================================
    // TODO: Inclua aqui seus testes para as questões 3, 4 e 5.
    // ================================================================================

    {
        std::cout << ">>> Q3-a: testando a funcao remove().\n";

        int A[] = { 1, 1, 2, 3, 3, 3, 3, 5, 5, 6 };
        auto new_l(prova::remove(std::begin(A), std::end(A), std::begin(A) + 1, std::begin(A) + 2, sizeof(int)));

        std::copy(std::begin(A), (int *) new_l, std::ostream_iterator< int >(std::cout, " ") );
    }

    {
        std::cout << ">>> Q4-a: testando a funcao contem().\n";

        int A[] = {1,2,3,4,5};
        int B[] = {1,2,3};
        if(prova::contem(std::begin(A), std::end(A), std::begin(B), std::end(B),sizeof(int), compare_ints)) printf("Deu certo\n");
        else printf("Nao deu certo\n");
    }

    {
        std::cout << ">>> Q4-b: testando a funcao contem().\n";

        int A[] = {1,2,3,4,5};
        int B[] = {1,3};
        if(prova::contem(std::begin(A), std::end(A), std::begin(B), std::end(B),sizeof(int), compare_ints)) printf("Deu certo\n");
        else printf("Nao deu certo\n");
    }

    {
        std::cout << ">>> Q4-c: testando a funcao contem().\n";

        int A[] = {1,2,3,4,5};
        int B[] = {1,2,3,4,5};
        if(prova::contem(std::begin(A), std::end(A), std::begin(B), std::end(B),sizeof(int), compare_ints)) printf("Deu certo\n");
        else printf("Nao deu certo\n");
    }

    {
        std::cout << ">>> Q4-d: testando a funcao contem().\n";

        int A[] = {1,2,3,4,5};
        int B[] = {6};
        if(prova::contem(std::begin(A), std::end(A), std::begin(B), std::end(B),sizeof(int), compare_ints)) printf("Deu certo\n");
        else printf("Nao deu certo\n");
    }

    {
        std::cout << ">>> Q5-a: testando a funcao remove_Rep().\n";

        int A[] = {1,2,2,3,4,5};
        auto target(2);
        auto new_l(prova::remove_repetidos(std::begin(A), std::end(A), &target, sizeof(int), compare_ints));

        std::copy(std::begin(A), (int *) new_l, std::ostream_iterator< int >(std::cout, " ") );
    }

    {
        std::cout << ">>> Q5-b: testando a funcao remove_Rep().\n";

        int A[] = {1,2,3,4,5};
        auto target(6);
        auto new_l(prova::remove_repetidos(std::begin(A), std::end(A), &target, sizeof(int), compare_ints));

        std::copy(std::begin(A), (int *) new_l, std::ostream_iterator< int >(std::cout, " ") );
    }

    {
        std::cout << ">>> Q5-b: testando a funcao remove_Rep().\n";

        int A[] = {1,2,3,4,5};
        auto target(5);
        auto new_l(prova::remove_repetidos(std::begin(A), std::end(A), &target, sizeof(int), compare_ints));

        std::copy(std::begin(A), (int *) new_l, std::ostream_iterator< int >(std::cout, " ") );
    }



    std::cout << "\n\n>>> Normal exiting...\n";

    return EXIT_SUCCESS;

}
