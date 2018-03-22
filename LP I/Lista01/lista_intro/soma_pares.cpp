#include <iostream>

using namespace std;

int main(void){
	int m, n;

	while (cin >> m >> n){
		int acc = 0;
		for(int i = m, j = 0; j < n; i++, j++) acc += i; 		
		printf("%i\n", acc);
	}
	 
	return 0;
}
