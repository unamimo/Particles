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

private:
	void processEvents();
	void update();
	void render();
	void init();

	void createParticle(sf::Color colour, sf::Vector2f position, float radius, float velocity);
	int getRandomNum(int upperRange);	// TODO: currently returns int, make it return a float later
	sf::Color pickRandomColour();

	sf::RenderWindow window = sf::RenderWindow (sf::VideoMode(K_WINDOWXY.x, K_WINDOWXY.y), "Particles");
	sf::Vector2u windowSize = window.getSize();

	// set particle start pos to middle of screen
	//Particle m_particle = Particle(windowSize.x / 2, windowSize.y / 2);
	//Particle m_particle2 = Particle((windowSize.x / 2 + 300), windowSize.y / 2);

	std::vector<Particle> m_vParticles;	// vector to store all particles

	// associate colours with numbers to get a random value
	const std::map<int, sf::Color> colourMap = {
		{0, sf::Color::Red},
		{1, sf::Color::Blue},
		{2, sf::Color::Green},
		{3, sf::Color::Yellow},
		{4, sf::Color::Magenta},
	};
};

#endif