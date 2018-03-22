#include <iostream>

using namespace std;

int main(void){
	int val[5];
	int acc = 0;
	for(int i = 0; i < 5; i++){
			cin >> val[i];		
			if(val[i] < 0) acc++;
	}
	cout << acc << " valores são negativos" << endl;

	return 0;
}
