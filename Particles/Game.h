#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//#include "Paddle.hpp"
//#include "Ball.hpp"
#include "Particle.h"

class Game {
public:
	Game();
	void run();
private:
	void processEvents();
	void update();
	void render();

	sf::RenderWindow window = sf::RenderWindow (sf::VideoMode(800, 600), "Particles");
	sf::Vector2u windowSize = window.getSize();

	Particle m_particle;
};

#endif