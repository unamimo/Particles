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

	void createParticle(sf::Color colour, sf::Vector2f position, float radius, float velocity);

	sf::RenderWindow window = sf::RenderWindow (sf::VideoMode(800, 600), "Particles");
	sf::Vector2u windowSize = window.getSize();

	// set particle start pos to middle of screen
	Particle m_particle = Particle(windowSize.x / 2, windowSize.y / 2);
	Particle m_particle2 = Particle((windowSize.x / 2 + 300), windowSize.y / 2);

	std::vector<Particle*> m_vParticles;	// vector to store all particles
};

#endif