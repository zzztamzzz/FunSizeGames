/*
Response checker and score updater
*/

#include <quiz_structure_cleanup.cpp>
#include <fstream>
#include <stdio.h>

using namespace std;
/*
Function to store user response.
For now, stick to making user select the presented choices
Later, take and analyze custom entered responses. (AI?)
*/
// int store_responses(){
//     int response_num = 0;
//     cin >> response_num;
//     // user may enter a weird number
//     for(load_question_file()){
//         if(response_num >= load_question_file.answer.size()){
//             cout << "You can't do that." << endl;    
//         }
//     }
// }

// function to check user response against input data
bool response_checker(bool isCorrect, bool isWrong, string userResponse, int choice){
}