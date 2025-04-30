// Lab 2 Exercise 5

#include <iostream>
using namespace std;

int main() {
    // original array
    int array1[] = {1, 4, 7, 10, 15};

    // get number of elements by dividing total array size with single element (in bytes) 
    int size = sizeof(array1) / sizeof(array1[0]);

    // New array to store reversed elements
    int array2[size];

    // move pointer to last element
    int* ptr = array1 + size - 1;

    // Traverse the array in reverse and store in array2
    for (int i = 0; i < size; i++) {
        // put value to array2 from pointer position
        array2[i] = *ptr;
        // move the pointer to the previous element
        ptr--;
    }

    // Print the elements of the reversed array
    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << array2[i] << " ";
    }
    cout << endl;

    // for executable file
    cout << "Press Enter to exit";
    cin.ignore();
    cin.get();
    return 0;
}