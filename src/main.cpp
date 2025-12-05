#include <iostream>
#include <string>

int main() {
  
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // TODO: Uncomment the code below to pass the first stage
  std::cout << "$ ";
  bool programIsRunning = true;
  
  while (programIsRunning) {
    
  
    std::string input;
    std::getline(std::cin, input);
  
    if(input == "exit") {
      programIsRunning = false;
    } else {
      std::cout << input << ": command not found" << std::endl;
    
      main();

    }

  }
  
}
