#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

// Function to add a student
void addStudent(vector<Student> &records) {
    Student s;
    cout << "Enter Roll No: ";
    cin >> s.roll;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Marks: ";
    cin >> s.marks;

    records.push_back(s);
    cout << "✅ Student added successfully!\n";
}

// Function to display all students
void displayStudents(const vector<Student> &records) {
    if (records.empty()) {
        cout << "No records to display.\n";
        return;
    }
    cout << "\n--- Student Records ---\n";
    for (auto s : records) {
        cout << "Roll: " << s.roll << ", Name: " << s.name << ", Marks: " << s.marks << "\n";
    }
}

// Function to search student by roll number
void searchStudent(const vector<Student> &records) {
    int roll;
    cout << "Enter roll number to search: ";
    cin >> roll;

    bool found = false;
    for (auto s : records) {
        if (s.roll == roll) {
            cout << "Found: Name: " << s.name << ", Marks: " << s.marks << "\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Student not found.\n";
}

// Function to delete a student
void deleteStudent(vector<Student> &records) {
    int roll;
    cout << "Enter roll number to delete: ";
    cin >> roll;

    for (auto it = records.begin(); it != records.end(); ++it) {
        if (it->roll == roll) {
            records.erase(it);
            cout << "🗑️ Student deleted.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void showMenu() {
    cout << "\n==== Student Record Manager ====\n";
    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student by Roll No.\n";
    cout << "4. Delete Student\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    vector<Student> records;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addStudent(records); break;
            case 2: displayStudents(records); break;
            case 3: searchStudent(records); break;
            case 4: deleteStudent(records); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
