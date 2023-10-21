// 1D game, "Life Sprint".

#include<iostream>
#include<conio.h>

using namespace std;
bool gameOver;
const int width = 20;
const int height = 16;

int a, b, foodX, foodY, specialfood, scoreCount;
int tailX[100], tailY[100];
int nTail;
enum eDirection {STOP = 0, LEFT,RIGHT, UP, DOWN}; // Controls
eDirection dir;

void setup(){
    gameOver = false;
    dir = STOP;
    a = width/2;
    b = height/2;
    // Spawn fruit for snake to eat
    foodX = rand() % width;
    foodY = rand() % height; 
    scoreCount = 0;
    for(int i = 0; i < width + 2; i++){
        cout << "#" << endl; 
    }
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            if(j == 0){
                cout << "#"; // walls
            }
            if(j == a && i == b){
                cout << "*"; // snake tail
            }
            else if(j == foodY && i == foodX){
                cout << "%";
            }
            bool print = false;
            for (int k = 0; k < nTail; k++){
                if(tailX[k] == j && tailY[k] == i){
                    cout << "*";
                    print = true;
                }
            }
            if(!print){
                cout << " ";
            }
            if(j == width -1){
                cout << "#" << endl;
                cout << "Score: " << scoreCount << endl;
            }
        }
    }
}
void Input(){
    
}
int main(){
    cout << "Welcome to Life Sprint!" << endl;

}