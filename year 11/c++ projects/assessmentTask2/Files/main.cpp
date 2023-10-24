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
#include <limits>
#include <fstream> // file stream
#include <string>
#include <iomanip> // Needed for using setw()
#include <vector>
#include <algorithm>

using namespace std;

//int menuValue; 
/* Learning from previous attempts! My number guessing game did
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

/* Struct needed for storing a name and score
*  Using a struct because by default all struct members are public.
*  Structs do also not allow null values (which we shouldn't be getting).
*/ 
struct Score {
    string name;
    int score;
};

// Pre-defining fns so they are in scope!
void menuHandler();
int getMenuValue();
void displayMenuMain();
void displayMenuAddScore();
void displayMenuScores(); // This is our menu score display
void getName();
void intro();
bool filterNegativeNums(int numIn);
void printButton(char inputVar, string textValue);
int getScore(string name);
void displayScores(); // This is our general high score display
bool compareScores(const Score& a, const Score& b);
void storeScore (string name, int score);
void sortScores(vector<Score> scores);

int main() {
    intro();

    system("pause>0");
    return 0;
}

void menuHandler () {
    storeScore(playerName, 0);
  
    if (inGame) {
        int answerValue;
        cout << "Answer: ";
        // Loop for game menu logic
        while (!(cin >> answerValue)) {
            cout << "Please enter a whole number, decimals aren't allowed!" << endl;
            cout << "Answer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    else {
        displayMenuMain();
    } 
}

// A function that: Grabs a menuValue (int) and returns it
int getMenuValue() {
    cout << "Enter a menu navigation value: ";
    int menuValue;
    /* This loop here is great, however it does have drawbacks.
    *  Say a user types the following text: "/jh1bd3", with
    *  this loop it is ignore, however if you instead use
    *  find_first_not_of("0123456789")!=string::npos
    */
    while (!(cin >> menuValue)) {
        cout << "invalid input detected!" << endl;
        cout << "Enter a menu navigation value: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return menuValue;
}

/* Yes I hear you! This does create more lines having each menu section
*  as a function however, compared to my previous system the readability
*  is ALOT better and that is what matters.
*  This code is also cleaner functioning and more portable (functions moment)
*/
void displayMenuMain() {
    system("cls");
    cout << 
    " _________________________________________ "
    "\n/                                         \\"
    "\n|      Multiplication & Divison Game      |"
    "\n|                Version: 1               |"
    "\n|              By Joseph Healy            |"
    "\n|           Player Name: " << setw(5) << playerName << "            |"
    "\n|        Best Highscore: " << setw(5) << getScore(playerName) << "            |"
    "\n\\_________________________________________/" << endl;
    printButton('1', "Play game");
    printButton('2', "Game Options");
    printButton('3', "Player Scoreboard");
    printButton('4', "Help");
    printButton('5', "Add a score");
    printButton('6', "Exit");
    switch (getMenuValue()) {
        case 1:
            cout << "Not implemented yet!";
            Sleep(1000);
            displayMenuMain();
            break;
        case 2:
            cout << "Not implemented yet!";
            Sleep(1000);
            displayMenuMain();
            break;
        case 3:
            displayMenuScores();
            break;
        case 4:
            cout << "Not implemented yet!";
            Sleep(1000);
            displayMenuMain();
            break;
        case 5:
            displayMenuAddScore();
            break;
        case 6:
            cout << "Not implemented yet!";
            Sleep(1000);
            displayMenuMain();
            break;
        default:
            cout << "That isn't a valid menu option!";
            Sleep(1000);
            displayMenuMain();
    }
}

void displayMenuAddScore() {
    system("cls");
    storeScore(playerName, getMenuValue());
    cout << "Added score, go check the scoreboard!";
    displayMenuMain();
}

void displayMenuScores() {
    system("cls");
    cout << " _________________________________________ "
         << "\n/                                         \\"
         << "\n|            Player scoreboard            |"
         << "\n|    View how you compare to the rest!    |"
         << "\n\\_________________________________________/" << endl;
    displayScores();
    printButton('1', "Go back to menu");
    switch (getMenuValue()) {
        case 1:
            displayMenuMain();
            break;
        default:
            cout << "That isn't a valid menu option!";
            Sleep(1000);
            displayMenuScores();
    }
}

void displayMenuOptions() {
    system("cls");
    printButton('1', "Change player name");
    printButton('2', "Change amount of questions");
    printButton('3', "View matrix of possible problems and answers");
    printButton('4', "Go back to menu");
}

void intro() {
    system("cls");
    cout << "Welcome to Joseph's Multiplication and Division Game!"
         << "\nTo navigate the menu input the numbers indicated next to each option"
         << "\nIf anything is confusing there is a help file provided,"
         << "\nthis can also be accessed at any time via the menu!"
         << "\nWhen you have finished reading this press any key to continue!" << endl;
    getch();
    system("cls"); // Ahh Akchewally this is insecure (nerd emoji).
    cout << "This game is best experienced in full-screen mode."
         << "\nYou can activate full-screen by pressing either:"
         << "\n- The rectangle next to the 'x' in the top right corner of the window."
         << "\n- Pressing the 'f11' key on your keyboard"
         << "\n- Pressing the 'Fn' and 'f11' keys at the same time"
         << "\nWhen you have finished reading this press any key to continue!" << endl;
    getch();
    system("cls");
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
            cout << "Input too long!" << endl;
            cout << "Please enter your player name: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    if (playerName.length() > 5) {
        cout << "\nThat name is too long! Remember, names must be 5 or less characters long.";
        getName();
    }
    else {
        cout << "\nYour name is " << playerName << ". Is this correct?"
             << "\nYou can type either '1' for yes or '2' for no." << endl;
        string choice;
        while(!(cin >> choice)) {
            cout << "invalid input detected!" << endl;
            cout << "You can type either '1' for yes or '2' for no." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (choice == "1") {
            menuHandler();
        }
        else {
            getName(); // send them back to the start!
        }
    }
}

bool filterNegativeNums(int numIn) {
    if (numIn > 0) {
        return true;
    }
    else {
        return false;
    }
}


/* I am literally hard coding the menu appearance, so instead
*  of writing out the button everytime I can just call this neat
*  little function here!
*/
void printButton(char inputVar, string textValue) {
    cout << " ___ "
         << "\n/   \\"
         << "\n| " << inputVar << " | " << textValue
         << "\n\\___/" << endl;
}

int getScore(string name) {
    // Read-only mode for our high scores
    ifstream highscoresR;
    highscoresR.open("highscores.txt");

    // Vector to store our Score structs for sorting
    vector<Score> highScores;
    if (highscoresR.is_open()) {
        string storePlayerName;
        int storePlayerScore;

        // Read our file and add the name and score to a struct, which is then added into the vector
        while (highscoresR >> storePlayerName >> storePlayerScore) {
            if (storePlayerName == name) {
                return storePlayerScore;
            }
            else {
                return 00000; // No high score present!
            }
        }
        highscoresR.close();
    }
    else {
        return 00000; // Couldn't open the file, no score present!
    }
    /* Note: The compilier throws a warning for no return statement being here
    *  however, there should be no chance that it gets to here
    */ 
}

// Pretty self-explanitory. A function that displays the score in our file
void displayScores() {

    // Open our file using fstream (output stream)
    ifstream highscoresR;
    highscoresR.open("highscores.txt");

    cout << "Name: " << setw(4) << ' ' << "Score: " << endl;
    if (highscoresR.is_open()) {
        string name;
        int score;
        while (highscoresR >> name >> score) {
            cout << left << setw(10) << name << setw(4) << score << endl;
        }
        highscoresR.close();
    }
    else {
        displayScores(); // try again until we can display the scores!
    }
    highscoresR.close(); // Just to be sure that it closes extirely
}

// Compare two structs scores, return true is A's score is greater than B's score
bool compareScores(const Score& a, const Score& b) {
    return a.score > b.score;
}

void storeScore (string name, int score) {
    bool playerExists;

    // Read-only mode for our high scores
    ifstream highscoresR;
    highscoresR.open("highscores.txt");

    // Vector to store our Score structs for sorting
    vector<Score> highScores;
    if (highscoresR.is_open()) {
        string storePlayerName;
        int storePlayerScore;

        // Read our file and add the name and score to a struct, which is then added into the vector
        while (highscoresR >> storePlayerName >> storePlayerScore) {
            if (storePlayerName == name) {
                playerExists = true;
                if (score > storePlayerScore) {
                    storePlayerScore = score;
                }
            }
        }
        // If the player doesn't exist, add them to the vector
        if(!playerExists) {
            highScores.push_back({storePlayerName, storePlayerScore});
        }
        highscoresR.close();
    }
    sortScores(highScores);

    // Writing the score to our file
    ofstream highscoresW;
    highscoresW.open("highscores.txt", ios::app);
    highscoresW << name << ' ' << score << endl;
}

void sortScores(vector<Score> scores) {
    // Write only file mode
    ofstream scoresWrite;

    // Sort function from the algorithm library to sort our structs based on number
    sort(scores.begin(), scores.end(), compareScores);
    scoresWrite.open("highscores.txt"); // Opening without append so it overwrite the existing content
    for (const auto& score : scores) {
        scoresWrite << score.name << ' ' << score.score << endl;
    }
    scoresWrite.close();
}