// Lab 2 Exercise 6

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// Define the Student struct with three attributes
struct Student {
    char name[50];
    int id;
    float grade;
};

// Function prototypes
void addStudent(vector<Student>& students);
void displayStudents(const vector<Student>& students);
void searchStudentByID(const vector<Student>& students);

int main() {
    // store student records
    vector<Student> students;
    int choice;

    do {
        // enter menu
        cout << "\nStudent Records Management System\n";
        cout << "1. Add a student\n";
        cout << "2. Display all students\n";
        cout << "3. Search for a student by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // handle menu options
        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                searchStudentByID(students);
                break;
            case 4:
                cout << "Exit.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

// Function to add a student
void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter student name: ";
    // clear input buffer
    cin.ignore();
    cin.getline(newStudent.name, 50);
    cout << "Enter student ID: ";
    cin >> newStudent.id;
    cout << "Enter student grade: ";
    cin >> newStudent.grade;
    students.push_back(newStudent);
    cout << "Student added successfully!\n";
}

// Function to display all students
void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to display.\n";
        return;
    }
    cout << "\nStudent Records:\n";
    for (const auto& student : students) {
        cout << "Name: " << student.name << ", ID: " << student.id << ", Grade: " << student.grade << "\n";
    }
}

// Function to search for a student by ID
void searchStudentByID(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to search.\n";
        return;
    }
    int searchID;
    cout << "Enter student ID to search: ";
    cin >> searchID;
    for (const auto& student : students) {
        if (student.id == searchID) {
            cout << "Student found: Name: " << student.name << ", ID: " << student.id << ", Grade: " << student.grade << "\n";
            return;
        }
    }
    cout << "Student with ID " << searchID << " not found.\n";
}