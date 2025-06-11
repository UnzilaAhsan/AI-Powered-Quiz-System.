#include "System.h"

// Constructor
System::System() : s_ct(0), a_ct(0) {}

// Load users from file
void System::loadUsers(const string& filename) {
    ifstream fin(filename);
    string role, name;
    int id;
    float avg;

    while (fin >> role) {
        fin >> name >> id;
        if (role == "Student") {
            fin >> avg;
            addStudent(Student(name, id, avg));
        } else if (role == "Admin") {
            addAdmin(Admin(name, id));
        }
    }
    fin.close();
}

// Add a student
void System::addStudent(const Student& s) {
    students.push_back(s);
    s_ct++;
}

// Add an admin
void System::addAdmin(const Admin& a) {
    admins.push_back(a);
    a_ct++;
}

// Find student by ID
Student System::findStudent(int ID) {
    for (int i = 0; i < s_ct; i++) {
        if (students[i].getID() == ID) return students[i];
    }
    throw runtime_error("student not found");
}

// Find admin by ID
Admin System::findAdmin(int ID) {
    for (int i = 0; i < a_ct; i++) {
        if (admins[i].getID() == ID) return admins[i];
    }
    throw runtime_error("admin not found");
}

// Update student average
void System::updateStudentAvg(int id, float newAvg) {
    for (int i = 0; i < s_ct; i++) {
        if (students[i].getID() == id) {
            students[i].UpdateAvg(newAvg);
            return;
        }
    }
}

// Destructor
System::~System() {}
