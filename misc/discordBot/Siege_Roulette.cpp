/*
Tamzid Choudhury
A discord bot driver file
Purpose: For R6S operator roulette
*/

#include <iostream>
#include "Op_Selector.h"
#include "Op_Selector.cpp"
using namespace std;

int main(){
    cout << "Welcome to Siege Roulette: Are you \n1. Attacking\n2. Defending?" << endl;
    int choice = 0;
    cin >> choice;
    try
    {
        /* code */
        if(choice == 1){
            return attackerChoice();
        }
        if(choice == 2){
            return defenderChoice();
        }
        else{
            cout << "Invalid Input. Please enter again" << endl;
        }
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}