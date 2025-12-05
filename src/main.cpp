#include <iostream>
#include <string>
using namespace std;
int main() {
  // Flush after every std::cout / std:cerr
  cout << unitbuf;
  cerr << unitbuf;

  // TODO: Uncomment the code below to pass the first stage
  while(true){

    cout << "$ ";
    string command;
    getline(cin, command);

    if(command == "exit") {
      break;
    } else {

      int currentIndex = 0;
      int commandLength = command.length();
      string inputCommand = "";
      bool inputCommandParsed = false;
      string inputUserString = "";

      while (commandLength >= currentIndex) {
        
        if (command[currentIndex] != ' ' && !inputCommandParsed) {
          inputCommand += command[currentIndex];
          currentIndex++;
        } else {
          inputCommandParsed = true;
          currentIndex++;

          if (currentIndex <= commandLength) {
            inputUserString += command[currentIndex];
          }

        }

      }

      if (inputCommand == "echo") {
        cout << inputUserString << endl ;  
      } else {
        cout << command << ": command not found"<<endl ;
      }
      
    }
      
  }


}