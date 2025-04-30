// Lab 1: Question 1: Using namespaces

#include <iostream>
#include <string>

// Namespace for MathOperations
namespace MathOperations {
    int summa(int a, int b) {
        return a + b;
    }
}

// Namespace for TextOperations
namespace TextOperations {
    std::string concat(const std::string& merkkijono1, const std::string& merkkijono2) {
        return merkkijono1 + merkkijono2;
    }
}

int main() {
    // Using MathOperations::summa
    int numero1 = 1, numero2 = 2;
    int sum = MathOperations::summa(numero1, numero2);
    std::cout << "Sum of " << numero1 << " and " << numero2 << " is: " << sum << std::endl;

    // Using TextOperations::concat
    std::string teksti1 = "tere, ";
    std::string teksti2 = "World!";
    std::string result = TextOperations::concat(teksti1, teksti2);
    std::cout << "Concatenated string: " << result << std::endl;

    // for executable file
    std::cout << "press Enter to exit";           
    std::cin.get();
    return 0;
}