// uppercase conversion

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string input;

    // prompt user for input
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    // convert string to uppercase
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);

    // output result
    std::cout << "Uppercase string: " << input << std::endl;

    // for executable file
    std::cout << "press Enter to exit";
    std::cin.get();     
    return 0;
}