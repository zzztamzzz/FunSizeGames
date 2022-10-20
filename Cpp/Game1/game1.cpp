/*
Rock, Paper and Scissor game
There will be a 1 in 3 change of guessing correctly
User should be able to choose a response
*/
#include<iostream>
#include<cmath>
using namespace std;

// Function Prototypes
int diceGame();

int main(){
    cout << "Are you ready to play?(Choose the option number)\n1. Play.\n2 Exit." << endl;
    int response = 0;
    cin >> response;
    do
    {
        /* code */
        cout << "Invalid response. Please enter 1 or 2!" << endl;
    } while (response > 2);
    if(response == 1){
        cout << "What kind of game would you like to play?\n1. Dice Game\n2. Rocks, papers & scissors.\n3. Flip a coin." << endl;
    }
}

/*
Dice game: You enter the number that could show up on the dice.
There is a 1 in 6 chance to get the correct response.
Play for 6 rounds, ie, roll rice 6 times and guess 6 times.
Keep track of score.
*/
int diceGame(){
    int diceFace = 0, score = 0;
    for(int unsigned i = 0; i <= 6; i++){
        srand(i);
    }
}