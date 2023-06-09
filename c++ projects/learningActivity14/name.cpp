/**********************************************************************************
* Simple Name program
*
* Author: Joseph Healy
* Last Updated: 8/6/2023
*
*
**********************************************************************************/

#include <iostream>
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
}

int main() {
    char choice;
    string name;

    // Generic filler text that asks the user for a name and greets them
    cout << "Hi there! I believe we haven't met before?" << endl;
    thinkingTime(5);
    cout << "\nThis silence is getting too awkward for me" << endl;
    thinkingTime(5);
    cout << "\nMay I know your name?\n" << "'y' for yes, 'n' for no" << endl;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores the maximum amount of characters

    if (choice == 'y') {
        cout << "Since you said yes what should I call you?" << endl;
        cin >> name;
        cout << "G'day " << name << ", How are ya?" << endl;
    }
    else {
        cout << "Okay then..." << endl;
        Sleep(750);
        cout << "Goodbye..." << endl;
    }

    system("pause>0");
}