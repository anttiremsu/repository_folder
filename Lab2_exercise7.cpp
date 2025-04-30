// Lab 2 Exercise 7

#include <iostream>
using namespace std;

int main(){
    int x = 100; 
    int* p1 = &x;  // Pointer 1 points to x 
    int* p2 = p1;  // Pointer 2 copies address (shallow copy)

    // Print the pointers and the value they point to
    cout << "Address stored in p1: " << p1 << endl;
    cout << "Value pointed to by p1: " << *p1 << endl;
    cout << "Address stored in p2: " << p2 << endl;
    cout << "Value pointed to by p2: " << *p2 << endl;

    // Modify the value of x using pointer p1
    *p1 = 200;

    // Print the updated value
    cout << "Updated value pointed to by p1: " << *p1 << endl;
    cout << "Updated value pointed to by p2: " << *p2 << endl;

    // for executable file
    cout << "Press Enter to exit";
    cin.get();    
    return 0;
}
// modifying p1 will update the value in p2 also