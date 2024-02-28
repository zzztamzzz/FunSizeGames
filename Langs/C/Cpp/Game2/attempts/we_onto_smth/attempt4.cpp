// File responsible to sort through the question data set
#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

/*
Q: ...
    '*'xN Correct N responses
    '-'xM Incorrect M reponses 
*/
// Keep at most 5 choices for simplicity
// So, 0 <= N, M <= 5; N+M = 5

struct Answer
{
    /* data */
    string a_text = "";
    // Assume user response is wrong, modify after mathcing later
    bool isCorrect;
};

struct Question
{
    /* data */
    string q_text = "";
    vector <Answer> answers;
};

// read question file
void loadr(const string& filename, vector <Question>& questions){
    // ifstream file("Q_A_set.txt");
    ifstream file(filename);
    string line;
    Question currentQ;
    bool parseQs = true;
    int q_count = 0;

    if(!file.is_open()){
        cout << "Error opening file" << endl;
        return;
    }

    while (getline(file, line)) {
        if (line.empty()) { // End of current question block
            questions.push_back(currentQ);
            currentQ = Question(); // Reset for the next question
            parseQs = true;
        } else if (parseQs) {
            currentQ.q_text = line.substr(3); // Skip "Q: "
            parseQs = false;
            q_count++;
        } else { // Parsing answers
            Answer answer;
            answer.isCorrect = line[0] == '*';
            answer.a_text = line.substr(2); // Skip "* " or "- "
            currentQ.answers.push_back(answer);
        }
    }
    if (!currentQ.q_text.empty()) {
        questions.push_back(currentQ);
    }
    
    file.close();
    cout << "Total Questions: " << q_count << endl;
}

int main() {
    cout << "Here's the list of questions" << endl;
    vector<Question> questions;
    loadr("Q_A_set.txt", questions);

    // Example usage
    for (const auto& question : questions) {
        cout << question.q_text << std::endl;
        for (const auto& answer : question.answers) {
            cout << (answer.isCorrect ? "* " : "- ") << answer.a_text << endl;
        }
    }
    return 0;
}