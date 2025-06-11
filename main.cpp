int main() {
    cout << "\t\t\t\t======================\n\t\t\t\tAI POWERED QUIZ SYSTEM\n\t\t\t\t======================\n\n";

    System s;
    s.loadUsers("users.txt");

    vector<Question<string>> questions;
    loadQuestions("quiz_questions.txt", questions);

    int choice;
    do {
        cout << "\n1. Login as Student\n2. Login as Admin\n3. Exit\nChoice: ";
        cin >> choice;
        Quiz q("Q001");

        switch (choice) {
        case 1: {
            int ID;
            cout << "Enter student ID: ";
            cin >> ID;
            try {
                Student student = s.findStudent(ID);
                cout << "Hello, " << student.getName() << "\n";
                cout << "Select Topic:\n1. Encapsulation\n2. Inheritance\n3. Polymorphism\n4. Go back\n";
                int topic_ch;
                cin >> topic_ch;
                if (topic_ch == 4) break;

                string topic = (topic_ch == 1 ? "Encapsulation" : topic_ch == 2 ? "Inheritance" : "Polymorphism");

                cout << "Previous performance: " << student.getAvg() << "\n";
                q.setDifficulty(student);
                cout << "Suggested difficulty: " << q.getDifficulty() << "\n";
                q.setTopic(topic);

                for (auto& question : questions) q.addQuestion(question);
                float newAvg = q.QuizFlow();
                s.updateStudentAvg(ID, newAvg);
            }
            catch (runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
        }

        case 2: {
            int ID;
            cout << "Enter Admin ID: ";
            cin >> ID;
            try {
                Admin admin = s.findAdmin(ID);
                cout << "Hello, " << admin.getName() << "\n";
                int ch;
                cout << "1. Delete question\n2. Add question\n";
                cin >> ch;
                if (ch == 1) {
                    int qid;
                    cout << "Enter Question ID to delete: ";
                    cin >> qid;
                    Question<string> target;
                    bool found = false;
                    for (auto& q : questions) {
                        if (q.getID() == qid) {
                            target = q;
                            found = true;
                            break;
                        }
                    }
                    if (found) {
                        admin.deleteQuestion(target, q, questions);
                        cout << "Question deleted.\n";
                    }
                    else {
                        cout << "Question not found.\n";
                    }
                }
                else if (ch == 2) {
                    admin.addQuestion(questions);
                }
            }
            catch (runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
        }

        }
    } while (choice != 3);

    return 0;
}
