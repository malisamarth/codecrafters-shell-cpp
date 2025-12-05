#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << unitbuf;
    cerr << unitbuf;

    while (true) {

        cout << "$ ";
        string command;
        getline(cin, command);

        if (command == "exit") {
            break;
        }

        int currentIndex = 0;
        int commandLength = command.length();
        string inputCommand = "";
        bool inputCommandParsed = false;
        string userInputString = "";

        // FIX: correct loop condition
        while (currentIndex < commandLength) {

            if (command[currentIndex] != ' ' && !inputCommandParsed) {
                inputCommand += command[currentIndex];
                currentIndex++;
            }
            else {
                inputCommandParsed = true;

                // FIX: read BEFORE increment
                if (currentIndex < commandLength) {
                    userInputString += command[currentIndex];
                }
                currentIndex++;
            }
        }

        // FIX: trim leading space
        if (!userInputString.empty() && userInputString[0] == ' ')
            userInputString.erase(0, 1);

        // FIX: trim trailing space
        while (!userInputString.empty() && userInputString.back() == ' ')
            userInputString.pop_back();

        if (inputCommand == "type") {

            if (userInputString == "echo" || 
                userInputString == "exit" || 
                userInputString == "type") {

                cout << userInputString << " is a shell builtin" << endl;
            }
            else {
                // FIX: no extra space before colon + include quotes
                string rawString = userInputString + ": not found";
                cout << rawString << endl;
            }

        } 
        else if (inputCommand == "echo") {
            cout << userInputString << endl;
        }
        else {
            // FIX: only print once
            cout << inputCommand << ": command not found" << endl;
        }
    }
}
