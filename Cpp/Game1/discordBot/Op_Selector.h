/*
Name:           Tamzid Choudhury
Discription:    A discord bot that helps users with Roulette Strat

Roulette Strat: Randomly selected operators to play in the game,
                if operator taken or banned then restart.
                Bonus: Select weapon loadout as well.
File details:   Contains user defined struct which stores informaiton
                about the operator being chosen. 
*/

#ifndef OP_SELECTOR
#define OP_SELECTOR

#include <string>

using namespace std;
// Struct definintion
struct OpFORS
{
    /* data */
    // Name of operator
    string OPname = "";
    // Weapon choice (stick to primary)
    string PrimaryWeapon = "";
};

#endif