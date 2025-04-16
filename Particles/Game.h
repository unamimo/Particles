#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Particle.h"
#include "Constants.h"
#include <random>

class Game {
public:
	Game();
	void run();

private:
	void processEvents();
	void update();
	void render();
	void init();

	void createParticle(sf::Color colour, sf::Vector2f startPos, float radius, float velocity, sf::Vector2i direction);
	void collideWithParticles(Particle particle1, Particle particle2); // check collission with any other particles

	int getRandomNum(int lowerRange, int upperRange);
	sf::Color getRandomColour();
	sf::Vector2<int> getRandomDirection();

	
	sf::RenderWindow window = sf::RenderWindow (sf::VideoMode(K_WINDOWXY.x, K_WINDOWXY.y), "Particles");
	sf::Vector2u windowSize = window.getSize();

	std::vector<Particle> m_vParticles;	// vector to store all particles
	//sf::Vector2i randomDir = getRandomDirection();

};

#endif