/**********************************************************************************
* Sum or product program
*
* Author: Joseph Healy
* Last Updated: 20/6/2023
*
*
**********************************************************************************/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

void sumProduct(string choice, int maxNum) {
    string userInput;

    int total = 1;
    if (choice == "s") {
        for (int i=0;i<maxNum+1;i++) {
            total += i;
        }
        cout << "The sum of numbers 1 to " << maxNum << " is:" << total << endl;
    }
    else {
        for (int i=1;i<maxNum+1;i++) {
            total = total * i;
        }
        cout << "The product of numbers 1 to " << maxNum << " is:" << total << endl;
    }


    while (choice != "y" && choice != "n") {
        cout << "Would you like to do another number? 'y' for yes, 'n' for no: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores the maximum amount of characters
    }
    string newNum;
    if (choice == "y") {
        cout << "Please enter a whole number, 3, 487 and 1000 are some examples" << endl;
        cin >> newNum;
        /* pre-test loop to prevent nefarious code busters!
        *  NOTE: in C++23 you can use std::string::contains("0123456789")
        */ 
        while (newNum.find_first_not_of("0123456789")!=string::npos) {
            cout << "Invalid input detected, please input a whole number!" << endl;
            cin >> newNum;
        }
        int realNum = stoi(newNum);
        cout << "Now, would you like to find the product of 1 to " << realNum
         << " or the sum of 1 to " << realNum << "? 'p' for product, 's' for sum" << endl;
        cin >> userInput;
        while (userInput.find_first_not_of("ps")!=string::npos) {
            cout << "Invalid input detected, please input 'p' for product or 's' for sum!" << endl;
            cin >> userInput;
        }
        sumProduct(userInput, realNum);
    }
    else {
        cout << "Goodbye!";
    }
}

int main () {


    cout << ".------------------------.\n"
			"| Sum or product program |\n"
			"|       Version 1        |\n"
			"|    By Joseph Healy     |\n"
			"'------------------------'" << endl;
    cout << "Please enter a whole number, 3, 487 and 1000 are some examples" << endl;
    string userInput;
    cin >> userInput;

    /* Sanitation of input, again as mentioned in another program you can use
    *  std::string::contains("0123456789") in c++23.
    */ 
    while (userInput.find_first_not_of("0123456789")!=string::npos) {
        cout << "Invalid input detected, please input a whole number!" << endl;
        cin >> userInput;
    }
    int realNum = stoi(userInput);
    cout << "Now, would you like to find the product of 1 to " << realNum
         << " or the sum of 1 to " << realNum << "? 'p' for product, 's' for sum" << endl;
    cin >> userInput;
    while (userInput.find_first_not_of("ps")!=string::npos) {
        cout << "Invalid input detected, please input 'p' for product or 's' for sum!" << endl;
        cin >> userInput;
    }
    sumProduct(userInput, realNum);

    system("pause>0");
    return 0;
}