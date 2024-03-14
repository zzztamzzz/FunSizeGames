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
  int a, b;
  std::cout << "Give me two numbers:" << std::endl;
  std::cin >> a >> b;
  int subtraction = a - b;
  std::cout << "The difference between the numbers: " << subtraction << std::endl;
  return 0;
}

int multiply(){
  int a, b;
  std::cout << "Give me two numbers to multiply:" << std::endl;
  std::cin >> a >> b;
  int multiplied = a * b;
  std::cout << "The product of the numbers: " << multiplied << std::endl;
  return 0;
}

int divide(){
  int a, b;
  std::cout << "Give me two numbers to divide:" << std::endl;
  std::cin >> a >> b;
  int divided = a / b;
  std::cout << "The division of the numbers: " << divided << std::endl;
  return 0;
}

int main(){
  // std::cout << "Hello, I am basic calculator. Please limit to two numbers. Select one of the options:" << std::endl;
  // std::cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Pi" << std::endl;
  // int choice;
  // std::cin >> choice;
  // if (choice == 1){
  //   addition();
  // }
  // if (choice == 2){
  //   subtraction();
  // }
  // if (choice == 3){
  //   multiply();
  // }
  // if (choice == 4){
  //   divide();
  // }
  // else{
  //   std::cout << "Functionality yet to be implemented" << std::endl;
  // }
  // return 0;
  std::cout << "Hello, I am basic calculator. Please limit to two numbers. Select one of the options:" << std::endl;
  std::cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Pi" << std::endl;
  int choice = 0;

  do
  {
    // int choice = 0;
    std::cin >> choice;
    if (choice == 1){
      addition();
    }
    if (choice == 2){
      subtraction();
    }
    if (choice == 3){
      multiply();
    }
    if (choice == 4){
      divide();
    }
    else {
      std::cout << "Functionality not available" << std::endl;
    }
  } while (choice <= 0); 
}