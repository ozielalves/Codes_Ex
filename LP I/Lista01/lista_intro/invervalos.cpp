#include <iostream>

using namespace std;

int main(void){
	int x;
	cout << "Entre com os valores inteiros (Ctrl + D para finalizar)" << endl;

	double int1=0, int2=0, int3=0, int4=0;
	int acc=0;

	while(cin >> x){
		if(x >= 0 && x < 25){
			int1++;
		}
		if(x >= 25 && x < 50) {
			int2++;
		}
		if(x >=50 && x < 75) {
			int3++;
		}
		if(x >= 75 && x <= 100) {
			int4++;
		}
		acc++;
	}

	if(acc == 0){
		printf("Você não preencheu nenhum número, tente novamente.\n");
		return 1;
	}	

	printf("Intervalo 1 [0, 25): \t%5.2lf%%\n", int1/acc*100);
	printf("Intervalo 2 [25, 50): \t%5.2lf%%\n", int2/acc*100);
	printf("Intervalo 3 [50, 75): \t%5.2lf%%\n", int3/acc*100);
	printf("Intervalo 4 [75, 100]: \t%5.2lf%%\n", int4/acc*100);

	return 0;
}
