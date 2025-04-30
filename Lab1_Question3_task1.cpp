// Lab 1 Question 3 task 1

#include <iostream>
using namespace std;
#define raja 50 // the macro

int main(){
    // Loop to print even numbers from 1 to 50
    for (int i = 2; i <= raja; i += 2) {
        cout << i << " ";
    }

    // for executable file
    std::cout << "\npress Enter to exit"; 
    std::cin.get();
    return 0;
}