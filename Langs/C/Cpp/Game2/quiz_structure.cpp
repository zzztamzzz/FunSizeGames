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
    Parse the input text file for all its contents
    An empty line separates the question and it's possible answers
    We have questions which started with "Q: ..."
    Then we have possible answers which:
        "* ..." for correct responses
        "- ..." for incorrect responses
    Sort through with these variables in the file
    */
    while (getline(file, line)) {
        
        if (line.empty()) { // End of current question block
            questions.push_back(currentQ);
            currentQ = Quiz(); // Reset for the next question
            parseQs = true;
        } else if (parseQs) {
            // currentQ.question_text = line.substr(3); // Skip "Q: "
            currentQ.question_text = line;
            parseQs = false;
        }
        // Parsing the answers section
        else {
            Answer answer;
            answer.isCorrect = line[0] == '*';
            answer.a_text = line.substr(2); // Skip "* " or "- "
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

// Driver to check logic
int main() {
    // cout << "Here's the list of questions:\n" << endl;
    vector<Quiz> questions;
    load_question_file("data.txt", questions);
    int q_count = 0;
    for (const auto& question : questions) {
        if(question.question_text != ""){
            q_count++;
        }
    }
    cout << "Total Questions in file: " << q_count << endl;

    // Example usage
    for (const auto& question : questions) {
        /*
        Print in this order
        Question...
        Correct choices..
        Incorrects...
        */
        cout << question.question_text << endl;
        cout << "Correct Answers:" << endl;
        for (const auto& answer : question.correct_answers) {
            cout << "* " << answer.a_text << endl;
        }
        cout << "Incorrect Answers:" << endl;
        for (const auto& answer : question.incorrect_answers) {
            cout << "- " << answer.a_text << endl;
        }
    }
    return 0;
}