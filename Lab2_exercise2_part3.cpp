// Lab 2 Exercise 2 part 3

#include <iostream>
using namespace std;

void swapusingReference(float &numero1, float &numero2){
	float temp = numero1;
	numero1 = numero2;
	numero2 = temp;
}

int main(){	
	float numero1 = 1;
	float numero2 = 2;

	swapusingReference(numero1,numero2);
	cout << numero1;
	cout << " and ";
	cout << numero2; // output now in the swapped order
	return 0;
}