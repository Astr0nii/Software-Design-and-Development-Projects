#include <iostream>
#include <string>
using namespace std;


// Function that contains the logic for encrypting and decrypting
void encryptDecrypt(string choice) {	
	string newChoice; // must be a string or bad things happen

	if (choice == "e") {
		string encryptedWord;
		string wordToEncrypt;

		cout << "Please input a word/phrase to be encrypted! ";
		cin.ignore();
		getline(cin, wordToEncrypt);

		// Amazing loop for encoding strings into ascii!
		for (int i = 0; i < wordToEncrypt.length(); i++) {
			char letter = wordToEncrypt.at(i);

			// ASCII doesn't use any negative numbers for character assignment
			unsigned int encryptedLetter = int(letter);
			encryptedWord = encryptedWord + " " + to_string(encryptedLetter);
		}

		// outputting the encoded phrase!
		cout << "Here is that word encrypted in ASCII: " << encryptedWord << endl;
		cout << "'e' for encrypting a word, 'd' for decrypting a word: ";
		cin >> newChoice;
		encryptDecrypt(newChoice);
	}
	else if (choice == "d") {
		string seqToDecrypt;
		string decryptedWord;
		string decryptedLetter;

		cout << "Please input a sequence to be decrypted\n"
				"(You must have spaces between the numbers (encrypted letters)! ";
		cin.ignore();
		getline(cin, seqToDecrypt);
		seqToDecrypt = seqToDecrypt + " ";


		// Amazing loop for decoding ascii sequences into phrases/words!
		for (int i = 0; i < seqToDecrypt.length(); i++) {
			char letter = seqToDecrypt.at(i);

			if (letter != ' ') {
				decryptedLetter = decryptedLetter + letter;
			}
			else if (letter == ' ') {
				unsigned int num = stoi(decryptedLetter);
				decryptedWord = decryptedWord + char(num);
				decryptedLetter = "";
			}
		}

		// ouputting the decoded phrase!
		cout << "Here is that sequence decrypted: " << decryptedWord << endl;
		cout << "'e' for encrypting a word, 'd' for decrypting a word: ";
		cin >> newChoice;
		encryptDecrypt(newChoice);
	}
	else {
		// Bug the user to enter the correct character
		while (newChoice != "e" && newChoice != "d") {
			cout << "'e' for encrypting a word, 'd' for decrypting a word: ";
			cin >> newChoice;
		}
		encryptDecrypt(newChoice);
	}
}

int main() {
	string encryptOrDecrypt; // must be a string because newChoice is a string

	cout << ".-------------------------------.\n"
			"| ASCII Encryptor and Decryptor |\n"
			"|           Version 1           |\n"
			"|        By Joseph Healy        |\n"
			"'-------------------------------'" << endl;

	cout << "'e' for encrypting a word, 'd' for decrypting a word: ";
	cin >> encryptOrDecrypt;

	encryptDecrypt(encryptOrDecrypt);

	system("pause>0");
}

