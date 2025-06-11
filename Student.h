#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
    float previous_avg;

public:
    Student(string n, int i, float avg);
    string getName() const override;
    int getID() const override;
    float getAvg() const;
    void UpdateAvg(float avg);
    ~Student();
};

#endif // STUDENT_H
