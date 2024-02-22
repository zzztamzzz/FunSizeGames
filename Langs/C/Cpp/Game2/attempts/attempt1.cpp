#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <random>

// #include <random.h>
using namespace std;

// Trackers, increment them 
int correct;
int incorrect;

struct QA_set{
    // Question and possible answer choices
    string question = "";
    string choice1 = "";
    string choice2 = "";
    string choice3 = "";
    string choice4 = "";
    string choice5 = "";
    string choice6 = "";
};

/*
Use a vector to store questions.
For now just the first 10 from the website
https://www.uscis.gov/sites/default/files/document/questions-and-answers/100q.pdf
*/
vector <QA_set> PossibileQuestions{
    {
        "What is the supreme law of the land?", 
        "The Constitution"
    },
    {
        "What does the Constitution do?", 
        "Sets up the Government", "Provides basic rights to Americans"},
    {
        "The idea of self-government is the first 3 words of the Constitution. What are they?",  
        "We The People."},
    {
        "What is an Amendment?", 
        "A change (to the Constitution)",
        "An addition (to the Constitution)"
    },
    {
        "What do we call the first ten amendments of the Constitution?", 
        "The Bill of Rights"
    },
    {
        "What is one of the rights by the First Amendment?", 
        "Speech", "Religion", "Assembly", "Press", "Petition the government"
    },
    {
        "How many amendments does the Constitution have?", 
        "27", "Twenty Seven"},
    {
        "What did the Decleration of Independence do?",
        "Announced our independence (from the Great Britain)",
        "Declared our independence (from the Great Britain)",
        "said that the United States is free (From the Great Britain)"
    },
    {
        "What are two rights in the Decleration of Independence?",
        "Life", "Liberty", "Pursuit of happiness"
    },
    {
        "What is freedom of religion?",
        "You can practice any religion, or not practice a religion."
    }
};

// Construct the question
class Question {
    private:
        // Ask the question
        string theQ;
        // Provide a list of choices
        string choice1, choice2, choice3, choice4, choice5, choice6;
    public:
    // Promt to give new question
    void askQuestion();
    
};

// Randomly select a question from the vector collection
int randomQuestionChoice(){
    // Get size of current vector and randomly select the question index number
    int sizeOfQAset = PossibileQuestions.size();
    return rand() % sizeOfQAset;
}

string leQuestion(){
    randomQuestionChoice();
    string myQ = PossibileQuestions.at(randomQuestionChoice());
    return myQ;
}
int main(){
    cout << "Welcome to the quiz" <<  endl;
    cout << "To respond to a question, type in the choices and hit ENTER key" << endl;
    // functions calls

    // call question caller

    // call answer checker function

    // keep track of the user score

    // keep user updated about current score

}
// Check if answer is correct
// bool checkGivenAnswer(){
//     string providedQuestion = randomQuestion();
//     string givenResponse;
//     cin >>  givenResponse;
// }
// Report correctness

// void passOrNot(){
//     bool pass == false;
//     for randomQuestion(){
//         if (checkGivenAnswer() == true){
//             pass = true;
//             case << "Correct!" << endl;
//         } else {
//             case << "Incorrect." << endl;
//         }
//     }
// }

