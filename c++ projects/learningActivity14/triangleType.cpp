#include <iostream>
#include <limits.h> // needed for "numeric_limits<streamsize>::max()"

using namespace std;

/* Function that takes an array of type float and compares each 'side' 
*  to determine the type of triangle the user has entered.
*/ 
void getTriangleType(float triangle[3]) {
    if (triangle[1] == triangle[2] && triangle[2] == triangle[3]) {
        cout << "Your triangle is an equilateral type!" << endl;
    }
    else {
        if (triangle[1] != triangle[2] && triangle[1] != triangle[3] && triangle[2] != triangle[3]) {
            cout << "Your triangle is an scalene type!" << endl;
        }
        else {
            cout << "Your triangle is an isosceles type!" << endl;
        }
    }
}

int main() {
    float triangle[3]; // an array of type float to store our triangle values.
    bool confirmTri;
    string userInput;

    cout << ".-------------------------------.\n"
			"|      Triangle Indentifier     |\n"
			"|           Version 1           |\n"
			"|        By Joseph Healy        |\n"
			"'-------------------------------'" << endl;

    // post-test loop to continue asking for a triangle until they are happy with one.
    do {
        cout << "Please enter 3 sizes for a triangle (make sure there is a space between the lengths)" << endl
             << "For example, 3 4 5 is a valid triangle, whilst 34 5 or 345 isn't" << endl;
        cin >> triangle[1] >> triangle[2] >> triangle[3];
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores the maximum amount of characters

        // Confirming if our user actually wants to proceed with this triangle.
        cout << "Side A length: " << triangle[1] << endl 
             << "Side B length: " << triangle[2] << endl
             << "Side C length: " << triangle[3] << endl
             << "Please type 'confirm' if these side lengths are correct, or 'restart' to make a new triangle"
         << endl;
        cin >> userInput;

        if (userInput == "confirm") {
            getTriangleType(triangle);
        }
        else {
            cout << "triangle discarded! Let's start anew!" << endl;
        }
    } while (!confirmTri);
}