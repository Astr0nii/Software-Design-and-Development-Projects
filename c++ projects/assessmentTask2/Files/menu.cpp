/**********************************************************************************
* Menu.cpp - A module that is responsible for: menu navigation and rendering
*
* Author: Joseph Healy
* Last Updated: 8/3/2023
*
*
**********************************************************************************/

#include <iostream>
#include <stdlib.h> // Needed for system("cls")
#include <Windows.h> // Needed for Sleep()
#include <conio.h> // Needed for getch()

using namespace std;

int menuValue; /* Learning from previous attempts! My number guessing game did
                * not use a global menu value. This resulted in the menu just
                * resetting back to the main menu everytime something went wrong.
                * Having this global variable means we can:
                * A) Inform the user that their value is incorrect and reset back
                *    to the current menu.
                * B) Have a single shared value that all subroutines can use.
                * 
                * Unfortunately point A means that our game will need a seperate
                * subroutine that doesn't clear the players history.
                * However, idea! We can clear the players guesses every time they
                * make a guess. When we clear it we can display all previous
                * guesses to the player!
                */

string playerName; // I do not want to parse this between everything

bool inGame = false;

#undef max /* Windows momento, Everyone hates and loves microsoft:
            * https://stackoverflow.com/a/21959303
            * Needed to #undef for use in "numeric_limits<streamsize>::max()"
            */ 

// Pre-defining fns so they are in scope!
void getName();
void displayMenu();

void menuHandler () {
  
    if (inGame) {
        int answerValue;
        // Loop for game menu logic
        while (!(cin >> answerValue)) {
            cout << "Answer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (!(cin >> answerValue)) {
                cout << "Please enter a whole number!";
                Sleep(2000);
                displayMenu(menuValue);
            }
        }
    }
    else {
        // Loop for main menu logic
        while (!(cin >> menuValue)) {
            cout << "Enter a menu navigation value: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (!(cin >> menuValue)) {
                cout << "Please enter a correct value!";
                Sleep(2000);
                displayMenu(menuValue);
            }
        }
    } 
}

void displayMenu(int menuValue) {
    system("cls");
}

void intro() {
    system("cls");
    cout << "Welcome to Joseph's Multiplication and Division Game!"
         << "\nTo navigate the menu input the numbers indicated next to each option"
         << "\nIf anything is confusing there is a help file provided,"
         << "\nthis can also be accessed at any time via the menu!"
         << "\nWhen you have finished reading this press any key to continue!" << endl;
    getch(); // wait for the user to press any key (very nice!)
    cout << "Now, before we begin I need a name from you."
         << "\nThis will be used to keep track of your scores!"
         << "\nYour name must be 1-5 Characters long."
         << "\nAn example of a short name is: A. Whilst a long name may be: Chloe"
         << "\nWhen you have finished reading this press any key to continue!" << endl;
    getch(); // wait for the user to press any key (very nice!)
    getName();
}

void getName() {
    system("cls");
    cout << "Please enter your player name: ";
    while(!(cin >> playerName)) {

    }
}