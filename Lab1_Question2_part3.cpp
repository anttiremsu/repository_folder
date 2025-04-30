// Lab1 Question2 part3

#include <iostream>
#include <string>
#include <algorithm> // For std::reverse

int main() {
    std::string merkkijono;

    // Take user input
    std::cout << "Enter a string: ";
    std::getline(std::cin, merkkijono);

    // Reverse the string using std::reverse
    std::reverse(merkkijono.begin(), merkkijono.end());

    // Print the reversed string
    std::cout << "Reversed string: " << merkkijono << std::endl;

    // for executable file
    std::cout << "press Enter to exit"; 
    std::cin.get();          
    return 0;
}