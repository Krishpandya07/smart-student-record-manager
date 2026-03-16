#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int id;
    string name;
    float marks;
};

vector<Student> students;

string calculateGrade(float marks) {
    if (marks >= 90) return "A+";
    else if (marks >= 80) return "A";
    else if (marks >= 70) return "B";
    else if (marks >= 60) return "C";
    else return "D";
}

void addStudent() {
    Student s;

    cout << "Enter Student ID: ";
    cin >> s.id;

    cout << "Enter Name: ";
    cin >> s.name;

    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);

    cout << "Student Added Successfully\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "No records found\n";
        return;
    }

    for (auto s : students) {
        cout << "\nID: " << s.id;
        cout << "\nName: " << s.name;
        cout << "\nMarks: " << s.marks;
        cout << "\nGrade: " << calculateGrade(s.marks);
        cout << "\n-------------------\n";
    }
}

void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (auto s : students) {
        if (s.id == id) {
            cout << "\nStudent Found\n";
            cout << "Name: " << s.name << endl;
            cout << "Marks: " << s.marks << endl;
            cout << "Grade: " << calculateGrade(s.marks) << endl;
            return;
        }
    }

    cout << "Student not found\n";
}

void updateStudent() {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    for (auto &s : students) {
        if (s.id == id) {
            cout << "Enter new name: ";
            cin >> s.name;

            cout << "Enter new marks: ";
            cin >> s.marks;

            cout << "Record Updated\n";
            return;
        }
    }

    cout << "Student not found\n";
}

void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            cout << "Student Deleted\n";
            return;
        }
    }

    cout << "Student not found\n";
}

void showTopper() {
    if (students.empty()) {
        cout << "No records\n";
        return;
    }

    Student topper = students[0];

    for (auto s : students) {
        if (s.marks > topper.marks)
            topper = s;
    }

    cout << "\nClass Topper\n";
    cout << "Name: " << topper.name << endl;
    cout << "Marks: " << topper.marks << endl;
}

void classAverage() {
    if (students.empty()) {
        cout << "No records\n";
        return;
    }

    float total = 0;

    for (auto s : students)
        total += s.marks;

    cout << "Class Average: " << total / students.size() << endl;
}

int main() {

    int choice;

    do {

        cout << "\n============================\n";
        cout << " SMART STUDENT RECORD MANAGER\n";
        cout << "============================\n";

        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Show Topper\n";
        cout << "7. Class Average\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: showTopper(); break;
            case 7: classAverage(); break;

        }

    } while (choice != 8);

}