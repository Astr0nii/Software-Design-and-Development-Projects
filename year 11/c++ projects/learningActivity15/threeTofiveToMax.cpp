/**********************************************************************************
* Adding multiples of 3 and 5 to a defined number
*
* Author: Joseph Healy
* Last Updated: 19/6/2023
*
*
**********************************************************************************/

#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main(); // pre-defining so the function is in scope


// Function for gettting a number from adding multiples of 3 and 5 to a max number
void getNumMulti3and5(int maxNum) {
    int total = 0;
    string choice;
    string newNum;

    /* Do Not use the mod operator >:C. Using a binary array is faster but in this case
    *  we cannot use an array since an array MUST have a constant value (Blame C for this).
    *  Sidenote, very interesting conversation about this solving the problem of finding
    *  multiples below. I remember you told us to not use the mod operator when we were
    *  first talking about the assignment, so I wanted to find a workaround for here too!
    *  https://stackoverflow.com/questions/9923198/finding-multiples-of-integers-quickly
    */
    for (int i=3;i<maxNum;i+=3) {
        total += i;
    }
    for (int i=5;i<maxNum;i+=5) {
        total += i;
    }

    cout << "The sum of numbers that are multiples of 3 and 5 from 1 to " << maxNum << " is " << total << endl;

    /* switch would be ideal here, but switch doesn't support strings and I am using a string
    *  to prevent nefarious program busters from breaking my code! >:C
    */
    while (choice != "y" && choice != "n") {
        cout << "Would you like to do another number? 'y' for yes, 'n' for no: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores the maximum amount of characters
        
    }
    if (choice == "y") {
        cin >> newNum;
        /* pre-test loop to prevent nefarious code busters!
        *  NOTE: in C++23 you can use std::string::contains("0123456789")
        */ 
        while (newNum.find_first_not_of("0123456789")!=string::npos) {
            cout << "Invalid input detected, please input a whole number!" << endl;
            cin >> newNum;
        }
        int realNum = stoi(newNum);
        getNumMulti3and5(realNum);
    }
    else {
        cout << "Goodbye!";
    }
}

int main () {
    string maxNum;

    /* TODO: Make this automatic, this shit looks ugly af rn
    *  Currently up to getting the details to display!
    *  Right now I've got it to render dynamically sized rectangles
    *  based on the length of the program name.
    */
    cout << ".--------------------------------------------------------.\n"
			"| Numbers from to with program with multiples of 3 and 5 |\n"
			"|                       Version 1                        |\n"
			"|                    By Joseph Healy                     |\n"
			"'--------------------------------------------------------'" << endl;
    cout << "Welcome! Please enter a number that you'd like to see added up to\n"
         << "Only multiples of 3 and 5 are considered.\n"
         << "For example, 10 would be numbers 1-10, due to the rules only 3,5,6,9 are added which equals 23!" << endl;
    cin >> maxNum;
    /* pre-test loop to prevent nefarious code busters!
    *  NOTE: in C++23 you can use std::string::contains("0123456789")
    */ 
    while (maxNum.find_first_not_of("0123456789")!=string::npos) {
        cout << "Invalid input detected, please input a whole number!" << endl;
        cin >> maxNum;
    }
    int realNum = stoi(maxNum);
    getNumMulti3and5(realNum);
    

    system("pause>0");
    return 0;
}