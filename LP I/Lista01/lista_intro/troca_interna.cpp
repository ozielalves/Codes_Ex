#include <iostream>

using namespace std;

// Função pra imprimir membros de um vetor
void imprimirVetor(int *começo, int *ultimo){
	for(int *i=começo; i <= ultimo; i++){
		printf("%i ", *i);
	}
	cout << endl;
}

// Função para trocar elementos
void swap(int *one, int *another){
	int *buf = (int *) calloc (1, sizeof(int));	
	//printf("Swapping %i by %i\n", *one, *another);
	*buf = *one;
	*one = *another;
	*another = *buf;
	free(buf);
}

int main(void){
	int tam = 20;
	int *vet = (int *)calloc(tam, sizeof(int));
	
	// Armazenar os 20 inteiros
	for(int i = 0; i < tam; i++){
		cin >> vet[i];
	}

	imprimirVetor(vet, &vet[tam-1]);
	
	// Fazer a troca dos elementos
	int *buf = (int *) calloc (1, sizeof(int));
	for(int i = 0, j = tam-1; i < tam/2; i++, j--){
		swap(&vet[i], &vet[j]);
	}

	imprimirVetor(vet, &vet[tam-1]);
	free(vet);
	return 0;	
}
