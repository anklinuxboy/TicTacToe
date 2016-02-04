/*
Copyright: Ankit Sharma
MIT License
 */

#include "../incld/header.h"

// class functions start.

// make the frame
void game::makeFrame() {
  std::string s = "...";
  for (int i = 0; i < 3; ++i)
    frame.push_back(s);
}

// read and print the frame
void game::readFrame() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cout << frame[i][j] << "  ";
    }
    std::cout << std::endl;
  }
}

bool game::writeFrame(int location, char c) {
  bool flag = 0;
  switch (location) {
    case 1:
      if (frame[0][0] == '.') {
        frame[0][0] = c;
        count++;
      } else {
        std::cout << "Can't overwrite. Try again.\n";
        flag = 1;
      }
    break;
    case 2:
      if (frame[0][1] == '.') {
        frame[0][1] = c;
        count++;
      } else {
        std::cout << "Can't overwrite. Try again.\n";
        flag = 1;
      }
    break;
    case 3:
      if (frame[0][2] == '.') {
        frame[0][2] = c;
        count++;
      } else {
        std::cout << "Can't overwrite. Try again.\n";
        flag = 1;
      }
    break;
    case 4:
      if (frame[1][0] == '.') {
        frame[1][0] = c;
        count++;
      } else {
        std::cout << "Can't overwrite. Try again.\n";
        flag = 1;
      }
    break;
    case 5:
      if (frame[1][1] == '.') {
        frame[1][1] = c;
        count++;
      } else {
        std::cout << "Can't overwrite. Try again.\n";
        flag = 1;
      }
    break;
    case 6:
      if (frame[1][2] == '.') {
        frame[1][2] = c;
        count++;
      } else {
        std::cout << "Can't overwrite. Try again.\n";
        flag = 1;
      }
    break;
    case 7:
      if (frame[2][0] == '.') {
        frame[2][0] = c;
        count++;
      } else {
        std::cout << "Can't overwrite. Try again.\n";
        flag = 1;
      }
    break;
    case 8:
      if (frame[2][1] == '.') {
        frame[2][1] = c;
        count++;
      } else {
        std::cout << "Can't overwrite. Try again.\n";
        flag = 1;
      }
    break;
    case 9:
      if (frame[2][2] == '.') {
        frame[2][2] = c;
        count++;
      } else {
        std::cout << "Can't overwrite. Try again.\n";
        flag = 1;
      }
    break;
  }
  return flag;
}

bool game::gameFinish(char c) {
  for (int i = 0, j = 0; i < 3; ++i, ++j) {
    if ((frame[i][0] == c && frame[i][1] == c && frame[i][2] == c) ||
      (frame[i][j] == c && frame[(i+1)%3][j] == c && frame[(i+2)%3][j] == c))
      return 1;
  }
  if ((frame[0][0] == c && frame[1][1] == c && frame[2][2] == c) ||
    (frame[0][2] == c && frame[1][1] == c && frame[2][0] == c))
    return 1;
  return 0;
}
// end of class functions

// welcome message
void welcome() {
  std::cout << "This is the tictactoe game. X always plays first." << std::endl
            << "Enter your choice. 1 for multiPlayer game, 0 for AI player." <<
            std::endl << "Good Luck!" << std::endl;
}

// frame structure
int frameNumber() {
  int num;
  while (!(std::cin >> num) || (!isdigit(num) && num == 0)) {
    std::cout << "Invalid input, try again: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return num;
}
/*
// sfml functions starts here

void sfmlStart() {
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tictactoe Game - ANS");
  window.clear(sf::Color::Blue);
  sfmlWelcome(window);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Num1 ||
            event.key.code == sf::Keyboard::Numpad1)
          sfmlMultiplayer(window);
        else if (event.key.code == sf::Keyboard::Num0 ||
                  event.key.code == sf::Keyboard::Numpad0)
          aiPlayer();
      }

      if (event.type == sf::Event::Closed) {
        window.close();
        break;
      }
    }
    window.display();
  }
}

void sfmlWelcome(sf::RenderWindow& window) {
  sf::Font font;
  try {
    font.loadFromFile("fonts/OpenSans-Regular.ttf");
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  // text on screen
  sf::Text text;
  text.setFont(font);
  text.setString("This is the TicTacToe game."
    "\nYou can choose to play with a human opponent or against the computer."
    "\nPress 1 to play against the human or 0 against the computer."
    "\nThe rules are thus - X always plays first. Good Luck!"
    "\nPress 1 or 0");
  text.setCharacterSize(14);
  text.setColor(sf::Color::White);
  text.setStyle(sf::Text::Bold);
  text.setPosition(10, 250);
  window.draw(text);
}

void sfmlPlayer1(sf::RenderWindow& window) {
  sf::Font font;
  try {
    font.loadFromFile("fonts/OpenSans-Italic.ttf");
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  // text on screen
  sf::Text text1;
  text1.setFont(font);
  text1.setString("Player 1: Enter a number between 1 and 9. \n");
  text1.setCharacterSize(14);
  text1.setColor(sf::Color::White);
  text1.setStyle(sf::Text::Bold);
  text1.setPosition(90, 20);
  window.draw(text1);
}

void sfmlMultiplayer(sf::RenderWindow& window) {
  window.clear(sf::Color::Blue);
  sfmlPlayer1(window);
}
*/

/*
  Game Functions - two player version.
 */
void multiPlayer() {
  game tic;
  bool positionVacant;
  char x = 'X';
  char o = 'O';
  int frameLocation;
  tic.makeFrame();
  while (count != 9) {
    if (count == 8) {
      std::cout << "Game Draw." << std::endl;
      break;
    }
    do {
      std::cout << "Player 1 plays. Enter a number between 1-9. \n";
      frameLocation = frameNumber();
      positionVacant = tic.writeFrame(frameLocation, x);
    } while (positionVacant == 1);
    tic.readFrame();
    if (tic.gameFinish(x)) {
      std::cout << "Player 1 wins!" << std::endl;
      break;
    }
    do {
      std::cout << "Player 2 plays. Enter number between 1-9. \n";
      frameLocation = frameNumber();
      positionVacant = tic.writeFrame(frameLocation, o);
    } while (positionVacant == 1);
    tic.readFrame();
    if (tic.gameFinish(o)) {
    std::cout << "Player 2 wins!" << std::endl;
    break;
    }
  }
}

/*
AI player version
 */

void aiPlayer() {
  return;
}
