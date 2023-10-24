/**********************************************************************************
* Simple Positive Greeting Message Name for only the names alice and bob
*
* Author: Joseph Healy
* Last Updated: 19/6/2023
*
*
**********************************************************************************/

#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <Windows.h> // needed to use "Sleep"
#include <limits> // needed for "numeric_limits<streamsize>::max()"

using namespace std;
#undef max /* Massive middle finger for taking this keyword windows >:C.
            *  https://stackoverflow.com/a/21959303
            *  Needed to #undef for use in "numeric_limits<streamsize>::max()"
            */ 


// Function for displaying a dotted waiting animation
void thinkingTime(int duration) {
    for (int i=0;i<duration;i++) {
        cout << ".";
        Sleep(750);
    }
    cout << '\n';
}

int main() {
    char choice;
    string name;

    // Generic filler text that asks the user for a name and greets them
    cout << "Hi there! I believe I've met you before?" << endl;
    thinkingTime(5);
    cout << "This silence is getting too awkward for me" << endl;
    thinkingTime(5);
    cout << "May I know your name?\n" << "'y' for yes, 'n' for no" << endl;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores the maximum amount of characters

    if (choice == 'y') {
        cout << "Since you said yes what should I call you?" << endl;
        cin >> name;
        // This just works - Todd Howard: https://stackoverflow.com/a/313990
        transform(name.begin(), name.end(), name.begin(), [](unsigned char c){ return tolower(c); });
        cout << name;
        if (name == "alice" || name == "bob") {
            cout << "\nOMG " << name << ". How are you! It has been so long!" << endl;
        }
        else {
            cout << "\nI wasn't expecting you!" << endl;
            thinkingTime(2);
            cout << "Scram!" << endl;
        }
    }
    else {
        // Pretending that computers have emotion KEK
        cout << "Okay then..." << endl; 
        Sleep(350);
        cout << "Goodbye..." << endl;
    }

    main();
    system("pause>0");
    return 0;
}