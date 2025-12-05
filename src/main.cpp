#include <iostream>
#include <string>
using namespace std;
int main() {
    // Flush after every std::cout / std:cerr
    cout << unitbuf;
    cerr << unitbuf;

    // TODO: Uncomment the code below to pass the first stage
    while (true) {

        cout << "$ ";
        string command;
        getline(cin, command);

        if (command == "exit") {
            break;
        }
        else {

            int currentIndex = 0;
            int commandLength = command.length();
            string inputCommand = "";
            bool inputCommandParsed = false;
            string userInputString = "";

            while (currentIndex < commandLength) {

                if (command[currentIndex] != ' ' && !inputCommandParsed) {
                    inputCommand += command[currentIndex];
                    currentIndex++;
                }
                else {
                    inputCommandParsed = true;

                    if (currentIndex < commandLength) {
                        userInputString += command[currentIndex];
                    }
                    currentIndex++;
                }

            }

            if (!userInputString.empty() && userInputString[0] == ' ') {
                userInputString.erase(0, 1);
            }

            if (inputCommand == "type") {

                if (userInputString == "echo" || userInputString == "exit" || userInputString == "type") {
                    std::cout << userInputString << " is a shell builtin" << std::endl;
                }
                else {
                    std::cout << userInputString << " : not found" << std::endl;
                }

            }
            else {
                if (inputCommand == "echo") {
                    cout << userInputString << endl;
                }
                else {
                    cout << command << ": command not found" << endl;
                }

            }


        }

    }


}
