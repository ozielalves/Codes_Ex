#include <iostream>

using namespace std;

int main(void){
	double vet[20];
	double menor[2]; // menor[0] = posição; menor[1] = valor menor elemento

	for(int i=0; i<20; i++){
		cin >> vet[i];

		if(i == 0) menor[0] = i, menor[1] = vet[i];
		else if(vet[i] < menor[1]) menor[0] = i, menor[1] = vet[i];
	}
	
	// Agora vamos imprimir os vetores armazenados
	for (int i=0; i<20; i++){
		printf("Posição %i: %.3lf\n", i, vet[i]);
	}

	// Agora imprimimos o menor valor junto com seu indice
	cout << "-----------------------------------" << endl;
	cout << "Menor valor:" << endl;
	printf("Posição %.0lf: %.3lf\n", menor[0], menor[1]);
	cout << "-----------------------------------" << endl;

	return 0;
}
