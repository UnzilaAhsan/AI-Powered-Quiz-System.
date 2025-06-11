#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Person.h"
#include "Quiz.h"
#include "Question.h"

using namespace std;

class Admin : public Person {
public:
    Admin(string n, int i);

    string getName() const override;
    int getID() const override;

    void deleteQuestion(const Question<string>& q, Quiz& Q, vector<Question<string>>& questions);
    void addQuestion(vector<Question<string>>& questions);

    ~Admin();
};

#endif // ADMIN_H
