// Lab 1 Question 3 task 2

#include <iostream>
using namespace std;
#define raja 50 // the macro

int main(){
    // Loop to print even numbers from 1 to 50
    // unsigned short optimizes memory efficiency
    for (unsigned short i = 2; i <= raja; i += 2) {
        cout << i << " ";
    }

    // for executable file
    std::cout << "\npress Enter to exit"; 
    std::cin.get();
    return 0;
}