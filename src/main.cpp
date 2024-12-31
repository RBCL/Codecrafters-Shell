#include <iostream>
#include <string.h>
#include <vector>

int main() {
    // Flush after every std::cout / std::cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    while (true) {
      std::cout << "$ ";
      bool word_start = false;
      std::string input;
      std::getline(std::cin, input);

        // Tokenize the input
      int len = input.length();
      char arr[len+1]; // string ends with null character hence n+1
      strcpy(arr,input.c_str()); // strcpy is coming from C library hence imported string.h
      std::vector<std::string> tokens; // this string is from C++ hence std library is used
      std::string st = "";
      for(int i=0;i<len;i++){
        char ch = arr[i];
      
        if (ch == ' '){
          if (!word_start){
          continue;
        }
          else{
          word_start = false;
          tokens.push_back(st);
          st = "";
        }
      }
        else{
          word_start = true;
          st += ch;
        }
      }
    tokens.push_back(st);

        // Recognize commands
        if (tokens[0] == "echo") {
            for (size_t i = 1; i < tokens.size(); ++i) {
                if (i == tokens.size() - 1) {
                    std::cout << tokens[i] << std::endl;
                } else {
                    std::cout << tokens[i] << " ";
                }
            }
            continue;
        } else if (tokens[0] == "exit") {
            exit(0);
        } else if (tokens[0] == "type") {
            if (tokens.size() > 1) {
                if (tokens[1] == "type" || tokens[1] == "exit" || tokens[1] == "echo") {
                    std::cout << tokens[1] << " is a shell builtin \n";
                } else {
                    std::cout << tokens[1] << ": not found" << std::endl;
                }
            } else {
                std::cout << "type: missing argument" << std::endl;
            }
            continue;
        } else {
            std::cout << tokens[0] << ": command not found" << std::endl;
        }
    }
}
