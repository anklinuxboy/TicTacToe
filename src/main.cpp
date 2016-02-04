/*
Copyright: Ankit Sharma
MIT License
 */

#include "../incld/header.h"

int count = 0;

int main() {
  // sfmlStart();
  // welcome message
  welcome();
  int choice;
  while (!(std::cin >> choice) || (choice != 1 && choice != 0)) {
    std::cout << "Invalid input, try again: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  if (choice == 1)
    multiPlayer();
  else
    aiPlayer();
  return 0;
}
