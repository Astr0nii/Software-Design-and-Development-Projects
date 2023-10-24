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
#include <limits> // needed for numeric_limits<streamsize>::max()
#include <time.h> // Needed for using time in srand()
#include <vector> // Needed to user vectors (duh)
#include <algorithm> // Needed for find()


using namespace std;
#undef max /* Massive middle finger for taking this keyword windows >:C.
            *  https://stackoverflow.com/a/21959303
            *  Needed to #undef for use in "numeric_limits<streamsize>::max()"
            */ 

string name; /* Defining the variable here so it is in scope for updateMenu()
             *  I do not want to parse a name into updateMenu(), only the menuVal
             */
int diffLevel = 2; /* This needs to be a global variable because the difficulty
                * is something that doesn't need to be parsed every single time
                * a function is called!
                */
string diffName = "Normal"; /* We need this variable for asthetics, and also
                            *  for using our difficulty in a switch statement
                            *  currently, as of c++ 23 switch statements cannot
                            *  support strings.
                            */

void getName(); // making sure it is in scope for updateMenu()
void updateMenu(int menuVal); // making sure it is in scope for gameLoop()

// Function for the game logic
void gameLoop() {
    int maxNum;

    // Assign a maximum number depending on diffculty
    switch (diffLevel) {
        case 1:
            maxNum = 100;
            break;
        case 2:
            maxNum = 1000;
            break;
        case 3:
            maxNum = 10000;
            break;
        case 4:
            maxNum = 100000;
            break;
        default:
            break;
    }
    srand((unsigned) time(NULL)); /* NULL Gets the number of seconds that have passed since
                                  * January 1st 1970 GMT 00:00:00, fun fact!
                                  */
    int computerNum = 1 + rand() % maxNum;

    cout << "Number Guessing Game"
         << "\nLatest Update: 20/7/23"
         << "\nThe number I am thinking of is between 1 and "
         << maxNum;
    int playerGuess;
    int playerGuesses = 0;
    /* Nerd Emoji time. We need a vector here because just setting a hard
    *  coded value for an array may work, but not in all cirumstances.
    *  What if a nefarious old man comes along and tries to break your
    *  maticulously crafted program, then what? We use a vector which
    *  dynamically re-sizes based on when values are inserted/removed!
    */
    vector<int> alreadyGuessed;

    // pre-test loop to handle player guessing
    while (playerGuess!=computerNum) {
        cout << "\nEnter a guess: ";
        while (!(cin >> playerGuess)) {
            cout << "\nEnter a guess: "; // Needed here so it prints every time the user enters an incorrect value
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (playerGuess>computerNum) {
            cout << "Your guess is too high!";
        }
        else if (playerGuess<computerNum) {
            cout << "Your guess is too low!";
        }
        else {
            cout << "You got my number!"
                 << "\nIt was " << computerNum
                 << "\nYou guessed my number in "
                 << playerGuesses
                 << " guesses!"
                 << "\nReturning to menu!";
        }
        /* The type returned will be std::vector<int>::iterator
        *  therefore we must use auto.
        */  
        auto findNum = find(alreadyGuessed.begin(), alreadyGuessed.end(), playerGuess);
        if (findNum != alreadyGuessed.end()) {
            cout << "You already guessed that number, therefore this guess wont count!";
        }
        else {
            alreadyGuessed.push_back(playerGuess);
            playerGuesses += 1;
        }
    }
    Sleep(5000);
    updateMenu(1);
}

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
                gameLoop();
            }
            else {
                updateMenu(0);
            }
            break;
        case 2:
            cout << "Difficulty"
                 << "\nCurrent Difficulty: " << diffName
                 << "\n1) Easy"
                 << "\n2) Normal"
                 << "\n3) Hard"
                 << "\n4) Extreme"
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
                        Sleep(1500);
                        updateMenu(2);
                        break;
                    case 2:
                        system("cls");
                        cout << "Difficulty set to normal!";
                        diffLevel = 2;
                        diffName = "Normal";
                        Sleep(1500);
                        updateMenu(2);
                        break;
                    case 3:
                        system("cls");
                        cout << "Difficulty set to hard!";
                        diffLevel = 3;
                        diffName = "Hard";
                        Sleep(1500);
                        updateMenu(2);
                        break;
                    case 4:
                        system("cls");
                        cout << "Difficulty set to extreme!";
                        diffLevel = 4;
                        diffName = "Extreme";
                        Sleep(1500);
                        updateMenu(2);
                        break;
                    default:
                        updateMenu(0); // go back to main menu
                        break;
                }
            break;
        case 3:
            cout << "Your current name is: " << name
                << "\nWould you like to change you name?"
                << "\n1) Yes"
                << "\n2) Back" << endl;

            while (!(cin >> menuVal)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            
            if (menuVal >= 2) {
                updateMenu(0);
            }
            else {
                getName();
            }
            break;
        case 4:
            system("cls");
            cout << "Exiting program...";
            Sleep(5000);
            system("pause>0");
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
    system("cls");
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