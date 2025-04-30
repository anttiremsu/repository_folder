// Lab 3 assignment 2

#include <iostream>
#include <string>
using namespace std;

class Student {

    private:
    string name;
    int age;
    char grade;
    string group = "2025 group";

    public:

    // Setters
    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    void setGrade(char g) {
        grade = g;
    }

    // Getters
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    char getGrade() {
        return grade;
    }

    // Display student info
    void displayInfo() {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Grade: " << getGrade() << endl;
        cout << "Group: " << group << endl;
    }
};

int main() {
    // make student
    Student oppilas;

    // Use setters to assign values
    oppilas.setName("mkikkihiiri");
    oppilas.setAge(5);
    oppilas.setGrade('F');

    // Use getters to retrieve and print values
    cout << "Using getters:" << endl;
    cout << "Name: " << oppilas.getName() << endl;
    cout << "Age: " << oppilas.getAge() << endl;
    cout << "Grade: " << oppilas.getGrade() << endl;

    // Call displayInfo to show student data
    cout << "\nUsing displayInfo:" << endl;
    oppilas.displayInfo();
}

// A: the program compiles because everything needing access to private is inside class
// B: setter functions inside class
// C: creates private string group and gives it value "2025 group"