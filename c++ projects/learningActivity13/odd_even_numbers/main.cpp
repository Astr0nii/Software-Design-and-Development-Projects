#include <iostream>

using namespace std;

// Function for looping through checking numbers, equipped with an option to exit
void checkNum(int input) {
    int newNum;


    if ((input % 2) > 0) {
        cout << "number is odd!" << endl;
    }
    else {
        cout << "number is even!" << endl;
    }
    cout << "Please input a number to find if it is even or odd: ";
    cin >> newNum;
    checkNum(newNum);
}

int main() {
    int inputNum;

    cout << ".-------------------------------.\n"
			"|  Even and Odd number checker  |\n"
			"|           Version 1           |\n"
			"|        By Joseph Healy        |\n"
			"'-------------------------------'" << endl;

    cout << "Please input a number to find if it is even or odd: ";
    cin >> inputNum;
    checkNum(inputNum);

    system("pause>0");
}