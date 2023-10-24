/**********************************************************************************
* Circle Circumference Program
*
* Author: Joseph Healy
* Last Updated: 19/6/2023
*
*
**********************************************************************************/

#define _USE_MATH_DEFINES // needed on some systems, visual studio code needs this :/

#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;


void calcCircle(double radius) {
    double circumference = 2*(M_PI*radius);
    char choice;

    cout << "The circumference of your circle is: " << circumference << endl;
    cout << "Would you like to do another circle? 'y' for yes, 'n' for no: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores the maximum amount of characters
    if (choice == 'y') {
        cout << "Please enter the radius of your cicle, the radius can be a whole or non-whole number: " << endl;
        cin >> radius;
        calcCircle(radius);
    }
    else {
        cout << "goodbye!" << endl;
    }
}

int main () {
    double radius; // Use doubles in almost every case, floats should only be used with justified reason :)

    cout << "Please enter the radius of your cicle, the radius can be a whole or non-whole number: " << endl;
    cin >> radius;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignoring extra numbers inputted by the user

    calcCircle(radius);

    system("pause>0");
    return 0;
}