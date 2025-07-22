#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int addition(int num1, int num2){
    int sum = num1+ num2;
    return sum;
}

int subtraction(int num1, int num2){
    int sum = num1-num2;
    return sum;
}

int division(int num1, int num2){
    if (num1 == 0|| num2 == 0){

    }
    int sum = num1/num2;
    
    return sum;
}
void displayMenu()
{
    std::cout << "==== CALCULATOR MAIN MENU ====";
    std::cout << "1. Addition";
    std::cout << "2. Subtraction";
    std::cout << "3. Multiplication";
    std::cout << "4. Division";
    std::cout << "5. Quit";
}

int main(){
    int choice;
    while (true){
        displayMenu();      //Display the menu for user's choice
        std::cin >> choice;
        switch(choice){
            case 1:
            std::cout << "You have chosen Addition!\n";
            case 2:
            case 3:
            case 4:

        }
    }
    
    
}