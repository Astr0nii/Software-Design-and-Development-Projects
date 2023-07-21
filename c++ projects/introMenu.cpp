/**********************************************************************************
* Intro Caller
*
* Author: Joseph Healy
* Last Updated: 6/9/2023
*
*
**********************************************************************************/

#include <iostream>
#include <string.h>

using namespace std;


void introMenu (string proName, string verNum, string author) {
    int nameLength = 4+(proName.length());
    int verLength = verNum.length();
    int authLength = author.length();
    int namePos = ((nameLength)/4);
    int verPos = ((nameLength)/verLength)-verLength;
    int authPos = ((nameLength)/authLength)-authLength;
    int hc;
    int wc;

    cout << '.';
    for (hc=0;hc<7;hc++) {
        for (wc=0;wc<nameLength; wc++) {
            switch (hc) {
                case 3:
                    if (wc == namePos) {
                        cout << proName;
                        wc += nameLength-1;
                    }
                /*case 3:
                    if (wc == verPos) {
                        cout << verNum;
                        wc += verLength;
                    }
                case 4:
                    if (wc == authPos) {
                        cout << author;
                        wc += authLength;
                    }*/
                default:
                    break;
            }
            if (hc != 0 && hc < 6) { 
                cout << '#';
            }
            else {
                cout << "-";
            }
        }
        if (hc == 0) {
            cout << '.' << endl;
            cout << '|';
        }
        else if (hc < 6) {
            cout << '|' << endl;
            if (hc < 5) {
                cout << '|';
            }
            else {
                cout << "'";
            }
        }
        else {
            cout << "'";
        }
    }
}

int main() {
    
    
    

    // Get the values for the menu thingo
    cout << "For testing purposes only at the moment " << endl;
    cout << "project value: " << endl;
    string project;
    cin >> project;
    cout << "version value: " << endl;
    string version; // Major.Minor.Patch, thus a string is needed
    cin >> version;
    cout << "creator value: " << endl;
    string creator;
    cin >> creator;
    introMenu(project, version, creator);
    
    system("pause>0");
    return 0;
}