/*
Copyright: Ankit Sharma
MIT License
 */

#ifndef GUARD_HEADER_H
#define GUARD_HEADER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cctype>
#include <exception>

// game functions declarations
void multiPlayer(void);
void aiPlayer(void);
void welcome(void);
int frameNumber(void);

/*// sfml functions declarations
void sfmlStart(void);
void sfmlWelcome(sf::RenderWindow& window);
void sfmlPlayer1(sf::RenderWindow& window);
void sfmlMultiplayer(sf::RenderWindow& window);*/

// macro declarations
#define HEIGHT 800         // for sfml window height
#define WIDTH 600         // for sfml window width

// variable declarations
extern int count;

class game {
 public:
  void makeFrame();
  void readFrame();
  bool writeFrame(int location, char c);
  bool gameFinish(char c);
 private:
  std::vector<std::string> frame;
};

#endif

// Note: Put Doxygen with the file
