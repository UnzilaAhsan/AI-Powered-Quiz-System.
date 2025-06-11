#include "Quiz.h"

// Constructor with only ID
Quiz::Quiz(string i) : ID(i), ct(0) {}

// Constructor with topic, difficulty, and ID
Quiz::Quiz(string t, string d, string i) : topic(t), difficulty(d), ct(0), ID(i) {}

// Set difficulty based on student average
void Quiz::setDifficulty(const Student& s) {
    if (s.getAvg() <= 50) difficulty = "Easy";
    else if (s.getAvg() <= 75) difficulty = "Medium";
    else difficulty = "Hard";
}

// Set topic
void Quiz::setTopic(string t) {
    topic = t;
}

// Getters
string Quiz::getID() const {
    return ID;
}

string Quiz::getTopic() const {
    return topic;
}

string Quiz::getDifficulty() const {
    return difficulty;
}

// Add question if it matches topic and difficulty
void Quiz::addQuestion(const Question<string>& q) {
    if (q.getDifficulty() == difficulty && q.getTopic() == topic) {
        questions.push_back(q);
        ct++;
    }
}

// Handle quiz flow and calculate score
float Quiz::QuizFlow() {
    int answer = 0, correct = 0;
    for (int i = 0; i < ct; i++) {
        questions[i].display();
        cin >> answer;
        if (answer == questions[i].getIndex() + 1) {
            cout << "Correct!\n";
            correct++;
        } else {
            cout << "Wrong!\n";
        }
    }

    cout << "Attempted: " << ct << "\nCorrect: " << correct << "\n";
    float avg = ((float)correct / ct) * 100;
    cout << "Average score: " << avg << "%\n";
    return avg;
}

// Delete question by shifting elements
void Quiz::deleteQuestion(const Question<string>& q) {
    for (int i = 0; i < ct; i++) {
        if (questions[i] == q) {
            for (int j = i; j < ct - 1; j++) {
                questions[j] = questions[j + 1];
            }
            ct--;
            break;
        }
    }
}

// Destructor
Quiz::~Quiz() {}
