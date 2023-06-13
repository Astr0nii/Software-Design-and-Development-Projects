/**********************************************************************************
* Adding numbers from 1 to a user specified number
*
* Author: Joseph Healy
* Last Updated: 9/6/2023
*
*
**********************************************************************************/

#include <iostream>
#include <limits>

using namespace std;

int main(); // pre-defining so the function is in scope

void getNum(int maxNum) {
    int total;
    char choice;

    for (int i=1;i<maxNum+1;i++) {
        total += i;
    }
    cout << "The total of numbers added from 1 to " << maxNum << " is: " << total << endl;;
    cout << "Would you like to do another number? 'y' for yes, 'n' for no";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores the maximum amount of characters
    if (choice == 'y') {
        main();
    }
    else {
        cout << "goodbye!" << endl;
    }
}

int main () {
    int maxNum;

    cout << ".-------------------------------.\n"
			"|    Numbers from to program    |\n"
			"|           Version 1           |\n"
			"|        By Joseph Healy        |\n"
			"'-------------------------------'" << endl;
    cout << "Welcome! Please enter a number that you'd like to see added up to: ";
    cin >> maxNum;
    getNum(maxNum);
    

    system("pause>0");
    return 0;
}