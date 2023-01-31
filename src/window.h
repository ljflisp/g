#pragma once
#include <iostream>
namespace window {
  void mainWindow() {
    std::cout << "\0337\033[?47htesting...\n";
    system("clear");
  }
  void exitWin() {
    std::cout << "\033[2J\033[?47l\0338";
  }
}