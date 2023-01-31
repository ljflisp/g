#include <iostream>
#include "./src/ansi/ansi.h"
#include "./src/window.h"
#include "./src/windowsize.h"
#include "./lib/strings.h"
using namespace ansi;
using namespace strings;

int lengthOfString(char* str) {
  int i = 0;
  while(str[i] != '\0')++i;
  return i;
}

char* repeat(char txt, int times) {
  char* temp = (char*)"";
  char* character = (char*)malloc(sizeof(char*));
  character[0] = txt;
  for(int i = 0; i < times; ++i) {
    temp = _ansi_internals::concat(temp, character);
  }
  return temp;
}

enum Mode {
  CMD,
  EDIT,
  NONE
};

int main() {
  Mode mode = NONE;
  char* filename = (char*)"test.txt";
  char header[] = "   Giga 0.0.1";

  String command = (char*)"";

  window::getSize();
  window::mainWindow();
  char input;

  int rows = window::size.rows;
  int hLen = lengthOfString((char*)header);
  int fLen = lengthOfString(filename);
  int diff = window::size.columns - (hLen + fLen);
  diff = diff/2;
  char* buffer = repeat(' ', diff);
  while(1) {
    system("clear");
    // Print Header
    std::cout << ANSI.bg.RGB(0,0,150) << ANSI.fg.White << header << buffer << filename << buffer << ANSI.control.Reset << '\n';

    // Print Placeholder for File
    for(int i = 0; i < rows-3; ++i) {
      std::cout << '\n';
    }

    // Print Footer
    std::cout << ANSI.bg.Blue << ANSI.fg.White << "Giga" << ANSI.control.Reset << '\n';
    if(mode == CMD)
    std::cout << '\r' << command.valueOf();
    if(mode == NONE)
      std::cout << '\r' << "Use : to start a command.";
    // Get Input
    system ("/bin/stty raw");
    input = getchar();
    system ("/bin/stty cooked");
    int toExit = false;
    if(mode == CMD) {
      if(input == 13) {
        mode = NONE;
        if(command == (char*)"exit") {
          toExit = true;
        }
        command = (char*)"";
        if(toExit)
          break;
      } else {
        command += input;
      }
    }
    // Process Input
    if(input == ':') {
      mode = CMD;
    }
  }
  window::exitWin();
  return 0;
}