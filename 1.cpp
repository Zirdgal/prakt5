#include <iostream>
#include <cstring>

using namespace std;

void printString(char* userString) {
    cout << "\nString:\n";

    char copyUserString[101];
    strcpy(copyUserString, userString);

    char *word = strtok(copyUserString, " ,.:;?!");
    int i = 0;

    while(word) {
        if (strlen(word) > 1) {
            cout << word << " ";
        }
        word = strtok(NULL, " .,:;?!");
    }
    cout << "\n";
}

void deleteCharacter(char* userString) {
    char userInput; 
    cout << "\nSelect a character to delete: ";
    cin >> userInput;

    if (cin.fail()) {
        cout << "\nType in a single character!";
        return;
    }

    int j = 0;

    for (int i =0; userString[i] != '\0'; i++) {
        if (userString[i] != userInput) {
            userString[j] = userString[i];
            j++;
        }
    }

    userString[j] = '\0';
    printString(userString);
}

void findFirstChar(char* userString) {
    char copyUserString[101];
    strcpy(copyUserString, userString);
    char userInput; 
    cout << "\nInput a character to find: ";
    cin >> userInput;

    if (cin.fail()) {
        cout << "\nType in a single character!";
        return;
    }

    cout << "\nWords that start with \"" << userInput << "\":\n";

    char *word = strtok(copyUserString, " ,.:;!?");

    while (word) {
        if (strlen(word)>1 && word[0] == userInput) {
            cout << word << "\t";
        }

        word = strtok(NULL, " ,.:;!?");
    }
    cout << "\n";
}

void wordCount(char* userString) {
    char copyUserString[101];
    strcpy(copyUserString, userString);
    char *word = strtok(copyUserString, " ,.;:!?");
    int wordCount = 0;
    while (word) {
        if (strlen(word) > 1) {
            wordCount++;
        }
        word = strtok(NULL, " ,.:;!?");
    }

    cout << "\nTotal number of words: " << wordCount << "\n";
}

void Menu(char* userString) {

    int option;
    int recursion = 1;
    // big beautiful menu
    
    while(recursion == 1) {
        cout << "\nPlease select one of the options below:";
        cout << "\n> (1) Delete a character";
        cout << "\n> (2) Find words that start with a character";
        cout << "\n> (3) Get the count of total words";
        cout << "\n> (4) Print all words";
        cout << "\n> (5) Exit";
        cout << "\n---------------------------------------";
        cout << "\nSelect an option(enter a number): ";
        cin >> option;
        cout << "---------------------------------------\n";
        
        if (cin.fail() || option > 5 || option < 1) {
            recursion = 0;
            cout << "\nPlease enter a whole number from 1 to 5!";
            return;
        }

        if (option == 1) {
            cout << "\nDeleting a character selected!\n";
            deleteCharacter(userString);
        }
        else if (option == 2) {
            cout << "\nFind words that start with a character selected!\n";
            findFirstChar(userString);
        }
        else if (option == 3) {
            cout << "\nWord count selected!\n";
            wordCount(userString);
        }
        else if (option == 4) {
            cout << "\nPrinting all words selected!\n";
            printString(userString);
        }
        else if (option == 5) {
            cout << "\nBye!\n";
            recursion = 0;
            return;
        }
    }
}

int main() {

    // get the starting string
    char userString[101];
    cout << "Please input a starting string:\n";
    cin.getline(userString, 101);

    if (cin.fail()) {
        cout << "Maximum string is 100 characters long!";
        return 1;
    }

    Menu(userString);
    return 0;
}



