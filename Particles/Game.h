#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Particle.h"
#include <algorithm>
#include <random>

class Game {
public:
	Game();
	void run();

	// CONSTANTS
	const sf::Vector2<int> K_WINDOWXY = { 800, 600 };
	const int K_NUMPARTICLES = 10;
	const float K_PARTICLERADIUS = 5.f;
	const float K_PARTICLEVELOCITY = 20.f;

	const sf::Vector2<int> K_UP = { 0, -1 };
	const sf::Vector2<int> K_UPRIGHT = { 1, -1 };
	const sf::Vector2<int> K_UPLEFT = { -1, -1 };
	const sf::Vector2<int> K_DOWN = { 0, 1 };
	const sf::Vector2<int> K_DOWNRIGHT = { 1, 1 };
	const sf::Vector2<int> K_DOWNLEFT = { -1, 1 };

	// associate directions with numbers to get a random value
	const std::map<int, sf::Vector2<int>> directionMap = {
		{0, K_UP},
		{1, K_UPRIGHT},
		{2, K_UPLEFT},
		{3, K_DOWN},
		{4, K_DOWNRIGHT},
		{5, K_DOWNLEFT}
	};

	// associate colours with numbers to get a random value
	const std::map<int, sf::Color> colourMap = {
		{0, sf::Color::Red},
		{1, sf::Color::Blue},
		{2, sf::Color::Green},
		{3, sf::Color::Yellow},
		{4, sf::Color::Magenta},
	};

private:
	void processEvents();
	void update();
	void render();
	void init();

	void createParticle(sf::Color colour, sf::Vector2f startPos, float radius, float velocity, sf::Vector2i direction);
	int getRandomNum(int lowerRange, int upperRange);
	sf::Color getRandomColour();
	sf::Vector2<int> getRandomDirection();


	sf::RenderWindow window = sf::RenderWindow (sf::VideoMode(K_WINDOWXY.x, K_WINDOWXY.y), "Particles");
	sf::Vector2u windowSize = window.getSize();

	std::vector<Particle> m_vParticles;	// vector to store all particles
	//sf::Vector2i randomDir = getRandomDirection();
};

#endif