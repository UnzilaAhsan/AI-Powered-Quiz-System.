#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;

public:
    Person(string n, int i);
    virtual string getName() const = 0;
    virtual int getID() const = 0;
    virtual ~Person();
};

#endif // PERSON_H
