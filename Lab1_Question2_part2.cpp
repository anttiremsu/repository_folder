#include <iostream>
#include <string>

// counter constantly refers to string input
int countVowels(const std::string& input) {
    
    // define vowels
    std::string vowels = "aeiouyAEIOUY";

    // init vowel counter
    int count = 0;

    // check for vowel in every char
    for (char ch : input) {
        // at the current position and increase counter if found
        if (vowels.find(ch) != std::string::npos) {
            count++;
        }
    }
    return count;
}

int main() {

    // get user input
    std::string inputString;
    std::cout << "Enter a string to count the vowels: ";
    std::getline(std::cin, inputString);

    // output the result of count
    int vowelCount = countVowels(inputString);
    std::cout << "Number of vowels: " << vowelCount << std::endl;

    // for executable file
    std::cout << "press Enter to exit"; 
    std::cin.get();     
    return 0;   
}