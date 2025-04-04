#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//#include "Paddle.hpp"
//#include "Ball.hpp"

class Game {
public:
	Game();
	void run();
private:
	void processEvents();
	void update();
	void render();

	sf::RenderWindow window;
	sf::Vector2u windowSize;

	//Paddle leftPaddle;
	//Paddle rightPaddle;
};

#endif