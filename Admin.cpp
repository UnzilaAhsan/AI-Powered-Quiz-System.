#include "Admin.h"

// Constructor
Admin::Admin(string n, int i) : Person(n, i) {}

// Get name
string Admin::getName() const {
    return name;
}

// Get ID
int Admin::getID() const {
    return id;
}

// Delete a question from quiz and global list, and update file
void Admin::deleteQuestion(const Question<string>& q, Quiz& Q, vector<Question<string>>& questions) {
    Q.deleteQuestion(q);

    for (int i = 0; i < questions.size(); i++) {
        if (questions[i] == q) {
            for (int j = i; j < questions.size() - 1; j++) {
                questions[j] = questions[j + 1];
            }
            questions.resize(questions.size() - 1);
            cout << "Question deleted from file\n";
            break;
        }
    }

    ofstream fout("quiz_questions.txt");
    for (int i = 0; i < questions.size(); i++) {
        fout << questions[i].getID() << '|'
             << questions[i].getText() << '|';

        const string* opts = questions[i].getOptions();
        for (int j = 0; j < 4; j++) {
            fout << opts[j] << '|';
        }

        fout << questions[i].getIndex() << '|'
             << questions[i].getDifficulty() << '|'
             << questions[i].getTopic() << '\n';
    }
    fout.close();
}

// Add a new question to memory and file
void Admin::addQuestion(vector<Question<string>>& questions) {
    int id, correct;
    string text, opt[4], diff, topic;

    cout << "Enter Question ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter question text: ";
    getline(cin, text);

    for (int i = 0; i < 4; i++) {
        cout << "Enter option " << i + 1 << ": ";
        getline(cin, opt[i]);
    }

    cout << "Enter index of correct option (0-3): ";
    cin >> correct;
    cin.ignore();

    cout << "Enter difficulty (Easy/Medium/Hard): ";
    getline(cin, diff);

    cout << "Enter topic: ";
    getline(cin, topic);

    Question<string> newq(text, opt, correct, diff, topic, id);
    questions.push_back(newq);

    ofstream fout("quiz_questions.txt", ios::app);
    fout << id << '|' << text << '|';
    for (int i = 0; i < 4; i++) fout << opt[i] << '|';
    fout << correct << '|' << diff << '|' << topic << '\n';
    fout.close();

    cout << "Question added successfully.\n";
}

// Destructor
Admin::~Admin() {}
