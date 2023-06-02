#include <iostream>

using namespace std;


char diffSettings() {
    char difficulty;
    

    while ((difficulty != 'e') && (difficulty != 'm') && (difficulty != 'h') && (difficulty != 'i')) {
        cout << "'e' for Easy (1 Number between 1 and 100)" << endl
         << "'m' for Medium (1 Number between 1 and 1000)" << endl
         << "'h' for Hard (1 Number between 1 and 10000)" << endl
         << "'i' for impossible (1 Number between 1 and 10000) ;)" << endl
         << "Please choose what difficulty you'd like to play this round! " << endl;
        cin >> difficulty;
    }
    
    return difficulty;
}


int randNum(char numDifficulty) {
    int maxNum;
    int randNumber;

    switch (numDifficulty) {
        case 'e':
            maxNum = 100;
            break;
        case 'm':
            maxNum = 1000;
            break;
        case 'h':
            maxNum = 10000;
            break;
        case 'i':
            maxNum = 10000;
            break;
        default:
            break;
    }
    srand((unsigned) time(NULL));
    randNumber = 1 + rand() % maxNum;
    return(randNumber);
}

void compareNumber(int randNumber, char numDifficulty) {
    float playerGuess;
    int maxNum;
    int playerGuesses = 0;

    switch (numDifficulty) {
        case 'e':
            maxNum = 100;
            break;
        case 'm':
            maxNum = 1000;
            break;
        case 'h':
            maxNum = 10000;
            break;
        case 'i':
            maxNum = 10000;
            break;
        default:
            break;
    }


    cout << "Please enter a guess, my number is between 1 and " << maxNum << endl;
    cin >> playerGuess;
    if (numDifficulty == 'i') {
        playerGuess += 0.01f;
    }
    playerGuesses += 1;
    do {
        if (playerGuess > randNumber) {
            cout << "Sorry, " << playerGuess << " is too high! My number is between 1 and " << maxNum << endl;
            playerGuesses += 1;
            cin >> playerGuess;
            if (numDifficulty == 'i') {
                playerGuess += 0.01f;
            }
        }
        else if (playerGuess < randNumber) {
            cout << "Sorry, " << playerGuess << " is too low! My number is between 1 and " << maxNum << endl;
            playerGuesses += 1;
            cin >> playerGuess;
            if (numDifficulty == 'i') {
                playerGuess += 0.01f;
            }
        }
    } while(playerGuess != randNumber);
    cout << "Wow! You guessed my number correctly, congratulations! You managed to do it in " << playerGuesses << " guesses!" << endl;
    main();
}

int main() {
    cout << ".-------------------------------.\n"
			"|  Random Number Guessing Game  |\n"
			"|           Version 1           |\n"
			"|        By Joseph Healy        |\n"
			"'-------------------------------'" << endl;

    char diff = diffSettings();
    cout << "Difficulty has been set to: " << diff << endl;
    int randNumber = randNum(diff);
    compareNumber(randNumber, diff);

    system("pause>0");
}