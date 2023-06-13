/**********************************************************************************
* Intro Caller
*
* Author: Joseph Healy
* Last Updated: 6/9/2023
*
*
**********************************************************************************/

#include <iostream>

using namespace std;

// string proName, float verNum, string author

void introMenu (int width, int height) {
    //int nameLength = proName.length();

    cout << '.';
    for (int hc=0;hc<height;hc++) {
        for (int wc=0;wc<width; wc++) {
            cout << '-';
        }
        if (hc == 0) {
            cout << '.' << endl;
            cout << '|';
        }
        else if (hc < height-1) {
            cout << '|' << endl;
            if (hc < height-2) {
                cout << '|';
            }
        }
        else {
            cout << "'";
        }
    }
}

int main() {
    string project;
    float version; // Major.Minor.Patch, thus a float is needed
    string creator;
    int width;
    int height;

    // Get the values for the menu thingo
    cout << "For testing purposes only at the moment " << endl;
    /*cout << "project value: " << endl;
    cin >> project;
    cout << "version value: " << endl;
    cin >> version;
    cout << "creator value: " << endl;
    cin >> creator;*/
    cout << "width value: " << endl;
    cin >> width;
    cout << "height value: " << endl;
    cin >> height;
    introMenu(width, height);
    
    system("pause>0");
    return 0;
}