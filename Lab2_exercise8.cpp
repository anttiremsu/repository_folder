// Lab 2 Exercise 8

#include <iostream>
using namespace std;

int main(){
    int a = 100;
    int& refA = a;  // Reference to a
    refA = 30;  // Modifying refA modifies a 

    // Print refA
    cout << "Value of refA: " << refA << endl;
    cout << "value of a: " << a << endl;

    //changing refA
    refA = 50;

    // Print refA and int a
    cout << "updated value of refA: " << refA << endl;
    cout << "updated value of a: " << a << endl;

    // for executable file
    cout << "Press Enter to exit";
    cin.get();    
    return 0;
}
// changing refA changes a also