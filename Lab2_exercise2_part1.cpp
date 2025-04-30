#include <iostream> 
using namespace std; 

template <class T> // function that swaps two numbers 
int swap_numbers(T& y, T& z) 
{ 
    T x; 
    x = y; 
    y = z; 
    z = x; 
    return 0; 
} 
 
int main() 
{ 
    float numero1, numero2; // declare the actual numbers
    // Prompt the user for two integers
    cout << "Enter the first integer: ";
    cin >> numero1;
    cout << "Enter the second integer: ";
    cin >> numero2; 
    swap_numbers(numero1, numero2); // swap
    cout << numero1; 
    cout << " and "; 
    cout << numero2 << endl; // output numbers in the swapped order

    cout << "press Enter to exit"; // for executable file
    cin.ignore();
    cin.get(); 
    return 0;
}