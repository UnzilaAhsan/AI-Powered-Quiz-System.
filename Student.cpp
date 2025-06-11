#include "Student.h"
Student::Student(string n, int i, float avg) : Person(n, i), previous_avg(avg) {}
string Student::getName() const {
    return name;
}
int Student::getID() const {
    return id;
}
float Student::getAvg() const {
    return previous_avg;
}
void Student::UpdateAvg(float avg) {
    previous_avg = avg;
}
Student::~Student() {}
