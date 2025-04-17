#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include <random>

class Helpers
{
public:
	static int getRandomNum(int lowerRange, int upperRange);
	static sf::Color getRandomColour();
	static sf::Vector2<int> getRandomDirection();
	static sf::Vector2<int> getCollisionAngle(std::string screenSide);	// "Up", "Down", "Right", "Left"
private:

};