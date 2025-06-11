#ifndef QUIZ_H
#define QUIZ_H

#include <iostream>
#include <vector>
#include <string>
#include "Question.h"
#include "Student.h"

using namespace std;

class Quiz {
    vector<Question<string>> questions;
    int ct;
    string topic;
    string difficulty;
    string ID;

public:
    Quiz(string i);
    Quiz(string t, string d, string i);

    void setDifficulty(const Student& s);
    void setTopic(string t);

    string getID() const;
    string getTopic() const;
    string getDifficulty() const;

    void addQuestion(const Question<string>& q);
    float QuizFlow();
    void deleteQuestion(const Question<string>& q);

    ~Quiz();
};

#endif // QUIZ_H
