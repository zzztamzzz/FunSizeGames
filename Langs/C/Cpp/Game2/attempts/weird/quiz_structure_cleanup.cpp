/*
Quiz Structure 
(10x) Q: ...
(n) correct choice(s)
(m) incorrect choice(s)

Purpose of file:
Read in questions from data text file.
Provide user with 10 randomly selected serialized questions
Show user some choices for responses
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // For sorting, if needed
#include <random>

using namespace std;

struct Answer
{
    string a_text = "";
    bool isCorrect; // This might be redundant with the new approach but can be kept for clarity or future uses
};

struct Quiz
{
    string question_text = "";
    vector<Answer> correct_answers;
    vector<Answer> incorrect_answers;
};

// read question file
void load_question_file(const string& filename, vector<Quiz>& questions) {
    ifstream file(filename);
    string line;
    Quiz currentQ;
    bool parseQs = true;
    // File not found
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    /*
    Parsing input string file 
    */
    while (getline(file, line)) {
        if (line.empty()) { 
            questions.push_back(currentQ);
            // new quiz structure per question
            currentQ = Quiz(); 
            parseQs = true;
        } else if (parseQs) {
            currentQ.question_text = line;
            parseQs = false;
        }
        // Parsing the answers section
        else {
            Answer answer;
            answer.isCorrect = line[0] == '*'; // correct response
            if (answer.isCorrect) {
                currentQ.correct_answers.push_back(answer);
            } else {
                currentQ.incorrect_answers.push_back(answer);
            }
        }
    }
    if (!currentQ.question_text.empty()) {
        questions.push_back(currentQ);
    }
    file.close();
}

/*
Function to randomly select a single question.
Selection needs to be made from the loaded text file
*/

void select_random_questions(const vector<Quiz>& questions, size_t count = 10) {
    // Assign a vector collection of numbers to the question for ordering purposes
    vector<int> selectedIndexes; 
    size_t questionsSize = questions.size();
    
    // random gen for selecting a question from vector question struct
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, questionsSize - 1);

    while (selectedIndexes.size() < count) {
        int index = distr(gen);
        // Check if the index is already used
        if (find(selectedIndexes.begin(), selectedIndexes.end(), index) == selectedIndexes.end()) {
            selectedIndexes.push_back(index);
            // print serialized questions
            cout << "Question " << selectedIndexes.size() << ": ";
            cout << questions[index].question_text.substr(3) << endl;
            // response spaces
            // cout << "Enter your response(s):" << endl;
            cout << endl; // "im walkin' hea"
        }
    }
}

// Driver to check logic
int main() {
    // cout << "Here's the list of questions:\n" << endl;
    vector<Quiz> questions;
    load_question_file("data.txt", questions);
    if (!questions.empty()) {
        // cout << "Selecting 10 random questions...\n" << endl;
        select_random_questions(questions);
    } else {
        cout << "No questions available. Please check the file path and format." << endl;
    }
    return 0;
}