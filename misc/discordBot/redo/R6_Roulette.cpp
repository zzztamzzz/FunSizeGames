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
// Container 3: Types of weapons to pick
vector <string> weaponChoice{
    "Assault Rifles",
    "Battle Rifles/DMR",
    "Shotguns",
    "SMG",
    "LMG"
};

// Method 1: Return a randomly selected attacker from container 1
string chosenAttacker(){
    // Container intex number
    srand(time(NULL));
    // Position of attackers in the string vector
    int index = attackerChars.size();
    // randomly choose a number between 0 and max length of container
    int randomly = rand() % index;
    /*
    Testing
    cout << "Testing random number to to be: " << randomly << endl;
    cout << "Test, random op is: " << attackChars[randomly] << endl;
    */
    return attackerChars[randomly];
}
// Method 2: Return a randomly selected defender from container 2
string chosenDefender(){
    srand(time(NULL));
    // Position of defenders in the string vector
    int position = defenderChars.size();
    int chosen = rand() % position;
    return defenderChars[chosen];
}
// Method 3: Return a randomly selected weapon of choice
string randomWeapon(){
    // Randomly select a gun. 
    srand(time(NULL));
    int containerIndex = weaponChoice.size();
    int chosen = rand() % containerIndex;
    return weaponChoice.at(chosen);
}


int main(){
    int userChoice = 0;
    // Header
    cout << "-----------Welcome to R6S Roulette-----------" << endl;
    do
    {
        cout << "Are you: 1) Attacking OR 2) Defending\nType your choice" << endl;
        cin >> userChoice;
        if(userChoice == 1){
            cout << "You are to play the operator: " << chosenAttacker() << endl;
            cout << "The weapons to choose from are: " << endl;
            for(int i = 0; i < weaponChoice.size(); i++){
                cout << weaponChoice.at(i) << endl;
            }
            cout << "And you will play: " << randomWeapon() << endl;
            cout << "If weapon not available, pick the 3rd successor from the list\nContinue until you have an avaialbe weapon" << endl;
        }
        if(userChoice == 2){
            cout << "Your defender chosen at random is: " << chosenDefender() << endl;
            // cout << "The weapons to choose from are: " << randomWeapon() << endl;
            // cout << "If weapon not available, pick the 3rd successor from the list\nContinue until you have an avaialbe weapon" << endl;
        }
    } while (/* condition */userChoice > 2);
}
/*
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
*/