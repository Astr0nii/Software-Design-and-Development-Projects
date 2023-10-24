/**********************************************************************************
* Multiplication table matrix program
*
* Author: Joseph Healy
* Last Updated: 26/06/2023
*
*
**********************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;



int main () {
    int curRow = 1; // we need to assign this for our pre-test while loop
    int rowNumbers = 12;
    int colNumbers = 12;


    while (curRow < rowNumbers+1)
    {
        for (int curCol = 1; curCol < colNumbers+1; curCol++)
        {
            // setw is used to set the width in the console of our text
            cout << setw(4) << curRow*curCol;
        }
        cout << endl;
        curRow++;
    }
    

    system("pause>0");
    return 0;
}