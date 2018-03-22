#include <iostream>

using namespace std;

int fib(int number){
	if(number == 0){
		return 1;
	}else{
		if (number == 1){
			return 1;
		}
		else{
			return (fib(number - 1) + fib(number - 2));
		}
	}	
}
int main(void){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		if(fib(i) < n){
			cout << fib(i) << " ";
		}else{
			cout << endl;
			break;
		}
	}
	return 0;
}
