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

// Checar se um número é par/impar
int par(int n){
	if(n%2 == 0){
		return 1; // é par
	}else{
		return 0; // é impar
	}
}

int main(void){
	int tam = 10;
	int *vet = (int *) calloc (tam, sizeof(int));

	// Armazenar valores no vetor
	for(int i = 0; i < tam; i++){
		cin >> vet[i];
	}

	// Imprimir conteúdo do vetor
	imprimirVetor(vet, &vet[tam-1]);

	// Realizar troca
	for(int i = 0; i < tam; i++){
		if(i != 0 && i != tam-1){
			// Se vet[i] for impar e vet[i+1] for par, troque
			//printf("Comparando %i com %i...\n", vet[i], vet[i+1]);
			if(par(vet[i]) == 0 && par(vet[i+1]) == 1){
				//printf("Trocando %i com %i\n", vet[i], vet[i+1]);
				swap(&vet[i], &vet[1+i]);
				i++;
			}
		}
	}

	imprimirVetor(vet, &vet[tam-1]);
	free(vet);
	return 0;
}
