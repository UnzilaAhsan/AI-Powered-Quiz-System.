#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Student.h"
#include "Admin.h"

using namespace std;

class System {
private:
    vector<Student> students;
    vector<Admin> admins;
    int s_ct, a_ct;

public:
    System();
    void loadUsers(const string& filename);
    void addStudent(const Student& s);
    void addAdmin(const Admin& a);
    Student findStudent(int ID);
    Admin findAdmin(int ID);
    void updateStudentAvg(int id, float newAvg);
    ~System();
};

#endif // SYSTEM_H
