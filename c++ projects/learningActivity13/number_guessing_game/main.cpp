#include <iostream>

using namespace std;


char diffSettings() {
    char difficulty;
    

    while ((difficulty != 'e') && (difficulty != 'm') && (difficulty != 'h') && (difficulty != 'x')) {
        cout << "'e' for Easy (Numbers between 1 and 100)" << endl
         << "'m' for Medium (Numbers between 1 and 1000)" << endl
         << "'h' for Hard (2 Numbers between 1 and 1000)" << endl
         << "'x' for Extreme (4 Numbers between 1 and 10000)" << endl
         << "Please choose what difficulty you'd like to play! " << endl;
        cin >> difficulty;
    }
    return difficulty;
}


int randNum(int maxNum, char numDifficulty) {
    int numOfNumsToGen;

    switch (numDifficulty) {
        case 'e':
            maxNum = 100;
            break;
        case 'm':
            maxNum = 1000;
            break;
        case 'h':
            numOfNumsToGen = 2;
            maxNum = 1000;
            break;
        case 'x':
            numOfNumsToGen = 4;
            maxNum = 10000;
            break;
        default:
            break;
    }

    int randNumber = rand() % maxNum + 1;
}

int main() {
    

    cout << ".-------------------------------.\n"
			"|  Random Number Guessing Game  |\n"
			"|           Version 1           |\n"
			"|        By Joseph Healy        |\n"
			"'-------------------------------'" << endl;

    char diff = diffSettings();
    cout << "Difficulty has been set to: " << diff;

    system("pause>0");
}