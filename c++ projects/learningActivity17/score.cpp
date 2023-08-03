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
#include <conio.h> // Needed for getch()
#include <ShlObj.h>
#include <windows.h>
#include <filesystem> // Needed to convert convert a Windows path to c++ path


/* https://stackoverflow.com/questions/66338153/undefined-reference-to-folderid-c
*  Windows Jank, KnownFolders declares the GUID without it being predefined.
*/
#define INITGUID
#define INITKNOWNFOLDERS

#include <KnownFolders.h> // Needed to use folder ids in SHGetKnownFolderPath()

using namespace std;

// Predefining functions here for the sake of cleanliness!
void displayScores();
void score(string name, int score);
filesystem::path GetPath();

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
void score (string name, int score) {

    // Writing the score to our file
    ofstream highscoresW;
    highscoresW.open(GetPath(), ios::app);
    highscoresW << name << ' ' << score << endl;

    // Read-only mode for our high scores
    ifstream highscoresR;
    highscoresR.open(GetPath());
    //"C:\\Users\\jeh12\\AppData\\Local\\highscores.txt"
    // Vector to store our Score structs for sorting
    vector<Score> highScores;
    if (highscoresR.is_open()) {
        // Read our file and add the name and score to a struct, which is then added into the vector
        while (highscoresR >> name >> score) {
            highScores.push_back({name, score});
        }
        highscoresR.close();
    }

    // Sort function from the algorithm library to sort our structs based on number
    sort(highScores.begin(), highScores.end(), compareScores);
    highscoresW.close(); // We need to close this to get rid of the append parameter
    highscoresW.open(GetPath()); // Opening without append so it overwrite the existing content
    for (const auto& score : highScores) {
        highscoresW << score.name << ' ' << score.score << endl;
    }
    highscoresW.close();

    displayScores(); // Only after sorting the scores should we display them!

    system("pause>0");
}

filesystem::path GetPath() {
    PWSTR path_tmp = NULL;
    HRESULT hr = SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, NULL, &path_tmp);

    filesystem::path pathVar;
    if (SUCCEEDED(hr)) {
        // file found!
        pathVar = path_tmp;
        pathVar += "\\highScores.txt";
    }
    else {
        cerr << "Appdata folder not found! Please repair windows installation!" << endl;
        getch();
    }
    /* VERY IMPORTANT: I will include this in the notes when submitting,
    *  however I will put it here just incase.
    *  To use CoTaskMemFree to free the path from memory since we aren't
    *  using it we need the library ole32, which needs to be linked
    *  since I am not using visual studio to compile this and you probably
    *  aren't either.
    *  When compiling make sure to include:
    *  -lole32
    *  after everything else!!
    *  ** ONLY WHEN USING G++ FOR WINDOWS!!!
    */
    
    
    CoTaskMemFree(path_tmp);
    return pathVar;
}

// Pretty self-explanitory. A function that displays the score in our file
void displayScores() {

    // Open our file using ifstream (output stream)
    ifstream highscoresR;
    highscoresR.open(GetPath());

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