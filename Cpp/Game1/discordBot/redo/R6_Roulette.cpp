#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

// struct opFors
// {
//     /* data */
//     string name = "";
// };


// Container 1: Choice of attackers
vector <string> attackChars{};
// Add the operators read from the text file "attackers.txt"
fstream myAttackers;
myAttackers.open("pool_of_attackers.txt");
// Container 2: Choice of defenders
vector <string> defenderChars{};
// Method 1, return a randomly selected attacker
string chosenAttacker(){
    // Container intex number
    srand(time(NULL));
    // Position of attackers in the string vector
    int index = attackChars.size();
    // randomly choose a number between 0 and max length of container
    int randomly = rand() % index;
    /*
    Testing
    cout << "Testing random number to to be: " << randomly << endl;
    cout << "Test, random op is: " << attackChars[randomly] << endl;
    */
    return attackChars[randomly];
}
string chosenDefender(){
    srand(time(NULL));
    // Position of defenders in the string vector
    int position = defenderChars.size();
    int chosen = rand() % position;
    return defenderChars[chosen];
}

int main(){
    cout << "Welcome to R6 Roulette. Are you\n1.Attacking\n2.Defending\n" << endl;
    int userChoice = 0;
    cin >> userChoice;
    if(userChoice == 1){
        cout << "You are going to play:\n" << chosenAttacker() << endl;
    }
    if(userChoice == 2){
        cout << "The defender is: \n" << chosenDefender() << endl;
    }
    else return 0;
}