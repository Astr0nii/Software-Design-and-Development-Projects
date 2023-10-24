/**********************************************************************************
* score.cpp - A module that: Creates a folder for the game to store stuff in and
              Creates a high score file (if it doesn't exit), adds 
*             names to it and sorts based on that players score!
*
* Author: Joseph Healy
* Last Updated: 31/7/2023
*
*
**********************************************************************************/

#include <iostream>
#include <fstream> // File manipulation
#include <iomanip>
#include <string>
#include <vector> // Needed for our vector we use to store scores
#include <algorithm> // Needed for sort()
#include "score.h" // Needed to use our functions accross files


using namespace std;

// Predefining functions here for the sake of cleanliness!
void displayScores();
void score(string name, int score);

// Struct needed for storing a name and score
struct Score {
    string name;
    int score;
};

// Compare two structs scores, return true is A's score is greater than B's score
bool compareScores(const Score& a, const Score& b) {
    return a.score > b.score;
}

/* Function that grabs a name + score and stores it into a file
*  All of these resources helped MASSIVELY with coding this:
*  Basic file manipulation - https://cplusplus.com/doc/tutorial/files/
*  Sorting strings - https://stackoverflow.com/questions/65458745/how-to-do-sorting-in-a-text-file-in-c
*  Sorting strings - https://www.geeksforgeeks.org/sorting-strings-from-the-text-file/
*  Ordering names on a scoreboard - https://stackoverflow.com/questions/27111971/c-ordering-the-names-of-a-scoreboard
*/ 
void storeScore (string name, int score) {

    // Writing the score to our file
    ofstream highscoresW;
    highscoresW.open("highscores.txt", ios::app);
    highscoresW << name << ' ' << score << endl;

    // Read-only mode for our high scores
    ifstream highscoresR;
    highscoresR.open("highscores.txt");

    // Vector to store our Score structs for sorting
    vector<Score> highScores;
    sortScores(highScores);
    if (highscoresR.is_open()) {
        // Read our file and add the name and score to a struct, which is then added into the vector
        while (highscoresR >> name >> score) {
            highScores.push_back({name, score});
        }
        highscoresR.close();
    }

    

    displayScores(); // Only after sorting the scores should we display them!
}

// A function that sorts our score file in order of highest to lowest
void sortScores(vector<Score> scores) {
    // Write only file mode
    ofstream scoresWrite;

    // Sort function from the algorithm library to sort our structs based on number
    sort(scores.begin(), scores.end(), compareScores);
    scoresWrite.open("highscores.txt"); // Opening without append so it overwrite the existing content
    for (const auto& score : scores) {
        scoresWrite << score.name << ' ' << score.score << endl;
    }
    scoresWrite.close();
}

// Pretty self-explanitory. A function that displays the score in our file
void displayScores() {

    // Open our file using ifstream (output stream)
    ifstream highscoresR;
    highscoresR.open("highscores.txt");

    cout << "Name: " << setw(4) << ' ' << "Score: " << endl;
    if (highscoresR.is_open()) {
        string name;
        int score;
        while (highscoresR >> name >> score) {
            cout << left << setw(10) << name << setw(4) << score << endl;
        }
        highscoresR.close();
    }
    else {
        displayScores(); // try again until we can display the scores!
    }
    highscoresR.close(); // Just to be sure that it closes extirely
}