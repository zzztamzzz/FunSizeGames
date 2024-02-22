#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <vector>
#include <iostream>

using namespace std;

// Quiz Game
// Ask Question, get response from user, report correct or incorrect
// Optional: Obtain user details, provide a user interface

// Score tracker
int successes;
int fails;

// Question Class
class Question {
private:
    string Question_Text;
    // Question may have multiple correct answers
    string Answer_1;
    string Answer_2;
    string Answer_3;
    string Answer_4;
    int Correct_Answer;
    int Question_Score;
 
public:
    // Setter Function
    void setValues(string, string, string, string, string, int, int);
    // Function to ask questions
    void askQuestion();
};

int main(){
    cout << "The program has started" << endl;
    Question q1;
    Question q2;
    Question q3;
   
}