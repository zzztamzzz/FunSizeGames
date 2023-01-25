#include "Op_Selector.h"
#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Store the name of all operators in a vector and access them randomly

// Container 1: All available attackers to choose from [33]
vector <OpFORS> attackerCollection{
    // Same Op can have different weapons (stricking to primary only)
    {"Sledge", "Assault Rifle"},
    {"Sledge", "Shotgun"},
    {"Thatcher", "Small mag AR"},
    {"Thatcher", "Same as sledge"},
    {"Thatcher", "Shotgun"},
    {"Ash", "R34C"},
    {"Ash", "G905"},
    {"Thermite", "AR"},
    {"Thermite", "Shotgun"},
    {"Twitch", "F12"},
    {"Twitch", "Shotgun"},
    {"Twitch", "DMR"},
    {"Montagne", "Revolver"},
    {"Montagne", "Regular pistol"},
    {"Glaz/Pablo", "Sniper"},
    {"Fuze", "AR"},
    {"Fuze", "LMG"},
    {"Fuze", "Shield"},
    {"IQ", "LMG"},
    {"IQ", "Primary 1"},
    {"IQ", "Primary 2"},
    {"Blitz", ""},
    {"Buck", "AR"},
    {"Buck", "DMR"},
    {"BlackBeard", "DMR"},
    {"BlackBeard", "AR"},
    {"Capitao", "LMG"},
    {"Capitao", "AR"},
    {"Hibana", "AR"},
    {"Hibana", "Shotgun"},
    {"Jackal", "AR"},
    {"Jackal", "Shotgun"}
};
// Container 2: All available defenders to choose from [33]
vector <OpFORS> defenderCollection;
// Method 1: Pick a random attacker
void attackerChoice(){
    // Select a random element from "attackerCollection"
    srand(0);
    int attColSize = attackerCollection.size(); // Position of element in the colleciton
    // Obtain a random index number
    int randomlySelectedOPindex = rand() % attColSize;
    // Print the element (the op) at that position
    return attackerCollection[randomlySelectedOP];
};
// Method 2: Pick a random defender
void defenderChoice(){

};