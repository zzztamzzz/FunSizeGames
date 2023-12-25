#include <iostream>
#include <math.h>
/*
int main() {
  
  std::cout << "I print, you see, we all set\n";
  std::cout << "Let's do some math. Give me two different numbers" << std::endl;
  int a, b;
  std::cin >> a;
  std::cin >> b;
  int addition;
  addition = a + b;
  std:: cout << "The numbers added are: " << addition << std::endl;
  return 0;
}
*/

int addition(){
  int a, b;
  std::cout << "Give me two numbers:" << std::endl;
  std:: cin >> a >> b;
  int addition = a + b;
  std::cout << "The numbers added are: " << addition << std::endl;
  return 0;
}

int subtraction(){
  
}

int main(){
  std::cout << "Hello, I am basic calculator. Select one of the options:" << std::endl;
  std::cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4.Division\n5.Pi" << std::endl;
  int choice;
  std::cin >> choice;
  if (choice == 1){
    addition();
  }
  else{
    std::cout << "Functionality yet to be implemented" << std::endl;
  }
  return 0;
}