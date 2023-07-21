/**********************************************************************************
* numberGuessingGame.cpp
*
* Author: Joseph Healy
* Last Updated: 18/7/2023
*
*
**********************************************************************************/

#include <iostream>
#include <stdlib.h> // Needed for system("cls")
#include <Windows.h> // Needed for Sleep()
#include <conio.h> // Needed for getch()
#include <limits>


using namespace std;
#undef max /* Massive middle finger for taking this keyword windows >:C.
            *  https://stackoverflow.com/a/21959303
            *  Needed to #undef for use in "numeric_limits<streamsize>::max()"
            */ 

string name; /* Defining the variable here so it is in scope for updateMenu()
             *  I do not want to parse a name into updateMenu(), only the menuVal
             */
int diffLevel; /* This needs to be a global variable because the difficulty
                * is something that doesn't need to be parsed every single time
                * a function is called!
                */
string diffName = "Normal"; /* We need this variable for asthetics, and also
                            *  for using our difficulty in a switch statement
                            *  currently, as of c++ 23 switch statements cannot
                            *  support strings.
                            */

// Function that grabs a menu value and "updates the menu". It is really messy.
void updateMenu(int menuVal) {
    system("cls");
    if (menuVal >= 5) {
        menuVal = 0;
    }
    switch (menuVal) {
        case 0:
            cout << "Number Guessing Game"
                 << "\nLatest Update: 20/7/23"
                 << "\nPlayer Name: " << name
                 << "\n1) Play"
                 << "\n2) Difficulty"
                 << "\n3) Name"
                 << "\n4) Exit" << endl;
                 /* A very neat while loop that prevents a specific old sleep-inducing teacher
                *  *cough* *cough* Mr Legge *cough *cough*. From breaking this program >:C
                */
                while (!(cin >> menuVal)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                updateMenu(menuVal);
            break;
        case 1:
            cout << "Play"
                 << "\nCurrent Options:"
                 << "\nPlayer Name: " << name
                 << "\nDifficulty Level: " << diffName
                 << "\n1) Continue"
                 << "\n2) Back" << endl; 
            while (!(cin >> menuVal)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (menuVal == 1) {
                system("cls");
                cout << "Not added yet!";
                Sleep(5000);
                updateMenu(0);
            }
            else {
                updateMenu(0);
            }
            break;
        case 2:
            cout << "Difficulty"
                 << "\n1) Easy"
                 << "\n2) Normal"
                 << "\n3) Hard"
                 << "\n4) Impossible"
                 << "\n5) Back" << endl;
                while (!(cin >> menuVal)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                switch (menuVal) {
                    case 1:
                        system("cls");
                        cout << "Difficulty set to easy!";
                        diffLevel = 1;
                        diffName = "Easy";
                        Sleep(2500);
                        updateMenu(1);
                        break;
                    case 2:
                        system("cls");
                        cout << "Difficulty set to normal!";
                        diffLevel = 2;
                        diffName = "Normal";
                        Sleep(2500);
                        updateMenu(2);
                        break;
                    case 3:
                        system("cls");
                        cout << "Difficulty set to hard!";
                        diffLevel = 3;
                        diffName = "Hard";
                        Sleep(2500);
                        updateMenu(3);
                        break;
                    case 4:
                        system("cls");
                        cout << "Difficulty set to impossible!";
                        diffLevel = 4;
                        diffName = "Impossible";
                        Sleep(2500);
                        updateMenu(4);
                        break;
                    default:
                        updateMenu(0); // go back to main menu
                        break;
                }
            break;
        case 3:
            cout << "Your current name is:" << name
                 << "\nWould you like to change you name?"
                 << "\n1) Yes"
                 << "\n2) No"
                 << "\n3) Back" << endl;
            while (!(cin >> menuVal)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (menuVal >= 3) {
                updateMenu(0);
            }
            else {
                system("cls");
                cout << "Not added yet!";
                Sleep(5000);
                updateMenu(3);
            }
            break;
        default:
            system("cls");
            cout << "Invalid menu value"
                 << "\nResetting to default!";
            Sleep(1000);
            updateMenu(0);
            break;
    }
}


/* See: https://stackoverflow.com/questions/6486289/how-can-i-clear-console for more info.
*  Apparently system("cls") is not very good for doing this, other implementations have
*  been shown on the page.
*  I have chosen to do system("cls") because this program doesn't need to stupid fast.
*  Modern Cpus are incredibly fast and the slowdown you experience is negligible.
*  There is apparently security threat too from using this, This is SDD though, not cyber security.
*/
void getName() {
    cout << "Welcome!"
         << "\nWhat may I call you?"
         << "\nYou can change this later!"
         << endl;
    cin >> name;
    system("cls");
    cout << "Welcome " << name << "! to Joseph's Number Guessing Game!"
         << "\nTo navigate the menu input the numbers indicated next to each option"
         << "\nWhen you have finished reading this press any key to continue!" << endl;
    getch(); // Wait until the user presses a key to continue (very nice)!
    updateMenu(0);
}

int main () {
    getName();
    

    system("pause>0");
    return 0;
}