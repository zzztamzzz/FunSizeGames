#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>
#include "R6_Roulette.h"

using namespace std;
// Container 1: Choice of attackers
vector <string> attackerChars{
    "Sledge","Thatcher",
    "Ash","Thermite",
    "Twitch","Montagne",
    "Fuze","Glaz",
    "IQ","Blitz",
    "Buck", "Blackbeard", "Capitao",
    "Hibana", "Jackal", "Ying",
    "Dokkaebi", "Finka", "Lion",
    "Maverick", "Nomad", "Gridlock",
    "Nokk", "Amaru", "Kali",
    "Iana", "Kali", "Ace",
    "Zero", "Flores", "Osa",
    "Sens", "Grim"
};
// Container 2: Choice of defenders
vector <string> defenderChars{
    "Smoke", "Mute",
    "Castle", "Pulse",
    "Doc", "Rook",
    "Jager", "Bandit",
    "Kapkan", "Tchanka",
    "Frost", "Valkyrie", "Caveria",
    "Echo", "Mira", "Lesion", "Ela"
    "Vigil", "Maestro", "Alibi",
    "Clash", "Kaid", "Mozzie",
    "Warden", "Goyo", "Wamai",
    "Oryx", "Melusi", "Aruni",
    "Thunderbird", "Thorn",
    "Azami", "Solis"
};

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