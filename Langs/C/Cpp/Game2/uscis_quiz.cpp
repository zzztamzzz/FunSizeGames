#include <iostream>
#include <vector>
#include "libxl.h"

using namespace std;

int main() {
    // Initialize libxl
    libxl::Book* book = libxl::createXMLBook();
    libxl::Status status = book->load("questions.xlsx");
    if (status != libxl::Status::Success) {
        cerr << "Error loading Excel file: " << status << endl;
        return 1;
    }

    // Access the worksheet containing the questions and choices
    libxl::Sheet* sheet = book->getSheet("Questions");
    if (sheet == nullptr) {
        cerr << "Error accessing worksheet: " << sheet << endl;
        return 1;
    }

    // Read the questions and choices from the worksheet
    vector<string> questions;
    vector<vector<string>> choices;
    int rows = sheet->getRows();
    for (int i = 1; i < rows; i++) {
        string question = sheet->getCell(i, 1)->getString();
        questions.push_back(question);

        int numChoices = sheet->getCell(i, 2)->getInt();
        vector<string> choiceVec;
        for (int j = 0; j < numChoices; j++) {
            string choice = sheet->getCell(i, 3 + j)->getString();
            choiceVec.push_back(choice);
        }
        choices.push_back(choiceVec);
    }

    // Present each question to the user and check their response
    for (int i = 0; i < questions.size(); i++) {
        cout << questions[i] << endl;
        for (int j = 0; j < choices[i].size(); j++) {
            cout << j + 1 << ". " << choices[i][j] << endl;
        }
        int response;
        cin >> response;
        if (response - 1 == sheet->getCell(i + 1, 2 + choices[i].size())->getInt()) {
            cout << "Correct!" << endl;
        } else {
            cout << "Incorrect. The correct answer is " << sheet->getCell(i + 1, 2 + choices[i].size())->getInt() + 1 << "." << endl;
        }
    }

    // Clean up
    book->release();
    libxl::destroy();

    return 0;
}