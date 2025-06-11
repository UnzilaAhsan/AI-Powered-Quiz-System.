#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Question {
private:
    string text;
    T options[4];
    int correctIndex;
    string difficulty;
    string topic;
    int id;

public:
    Question() : text(""), correctIndex(-1), difficulty(""), topic(""), id(0) {}

    Question(string t, T o[4], int c, string d, string to, int i)
        : text(t), correctIndex(c), difficulty(d), topic(to), id(i) {
        for (int i = 0; i < 4; i++) options[i] = o[i];
    }

    string getText() const { return text; }
    string getTopic() const { return topic; }
    int getID() const { return id; }
    const T* getOptions() const { return options; }
    int getIndex() const { return correctIndex; }
    string getDifficulty() const { return difficulty; }

    bool operator==(const Question& other) {
        return id == other.id;
    }

    void display() const {
        cout << "\n[ID: " << id << "] Q. " << text << "?\n";
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << options[i] << ".\n";
        }
    }

    ~Question() {}
};

#endif // QUESTION_H
