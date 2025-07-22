#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <cmath>
//Returns the addition of two numbers
double addition(int num1, int num2){
    int sum = num1+ num2;
    return sum;
}

//Returns the subtraction of two numbers
double subtraction(int num1, int num2){
    int sum = num1-num2;
    return sum;
}
//Returns the multiplication of two numbers
double multiplication(int num1, int num2){
    double sum = num1 * num2;
    return sum;
}
//Returns the division of two numbers
double division(int num1, int num2){
    if(num2 == 0){
        throw std::runtime_error("ERROR:DIVISION BY ZERO!\n");
    }
    double sum = num1/num2;
    return sum;
}
//displays the menu
void displayMenu()
{
    std::cout << "==== CALCULATOR MAIN MENU ====" << std::endl;
    std::cout << "1. Addition" << std::endl;
    std::cout << "2. Subtraction" << std::endl;
    std::cout << "3. Multiplication" << std::endl;
    std::cout << "4. Division" << std::endl;
    std::cout << "5. Quit" << std::endl;
}

int main(){
    int choice;
    double num1, num2;
    double sum;
    while (true){
        displayMenu();                                          //Display the menu for user's choice
        std::cin >> choice;
        switch(choice){
            case 1:                                             //User has chosen option 1 (Addition)  
                std::cout << "You have chosen Addition!\n";
                std::cout << "Please enter two numbers:\n";
                std::cin >> num1 >> num2;
                std::cout << "Number 1:" << num1 << std::endl;
                std::cout << "Number 2:" << num2 << std::endl;
                sum = addition(num1, num2);
                std::cout << "The result of " << num1 << " + "<< num2 << " is: " << sum << std::endl;
                break;

            case 2:                                             //User has chosen option 2 (Subtraction)
                std::cout << "You have chosen Subtraction!\n";
                std::cout << "Please enter two numbers:\n";
                std::cin >> num1 >> num2;
                std::cout << "Number 1:" << num1 << std::endl;
                std::cout << "Number 2:" << num2 << std::endl;
                sum = subtraction(num1, num2);
                std::cout << "The result of " << num1 << "-" << num2 << " is: " << sum << std::endl;
                break;

            case 3:                                             //User has chosen option 3 (Multiplication)
                std::cout << "You have chosen Multiplication!\n";
                std::cout << "Please enter two numbers:\n";
                std::cin >> num1 >> num2;
                std::cout << "Number 1:" << num1 << std::endl;
                std::cout << "Number 2:" << num2 << std::endl;
                sum = multiplication(num1, num2);
                std::cout << "The product of " << num1 << " and " << num2 << " is: " << sum << std::endl;
                break;

            case 4:                                             //User has chosen option 4 (Division)
                std::cout << "You have chosen Division\n";
                std::cout << "Please enter two numbers:\n";
                std::cin >> num1 >> num2;
                std::cout << "Number 1:" << num1 << std::endl;
                std::cout << "Number 2:" << num2 << std::endl;
                try{
                    sum = division(num1, num2);
                    std::cout << num1 << " divided by " << num2 << " is: " << sum << std::endl;
                }
                catch(std::runtime_error& e){
                    std::cout <<"Exception occured"<< std::endl << e.what();
                }
                break;

            case 5:                                             //User has chosen option 5 (Quit/Exit)
                std::cout << "EXITING PROGRAM!\n";
                std::cout << "GOODBYE!";
                return 0;

            default:                                            //Invalid choice option. Print Menu
            std::cout << "Invalid choice. Please try again!\n";
            break;
        }
    } 
    
}