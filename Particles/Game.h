#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Particle.h"
#include "Constants.h"
#include <random>
#include <thread>		// threading, https://iamsorush.com/posts/cpp-std-thread/
#include <functional>

class Game {
public:
	Game();
	void run();

private:
	void processEvents();
	void update(int threadItr);
	void render();
	void init();
	void shutdown();

	void createParticle(sf::Color colour, sf::Vector2f startPos, float radius, float velocity, sf::Vector2i direction);
	void checkParticleCollision(Particle* particle1, Particle* particle2); // check collission with any other particles
	void deleteParticle(Particle* m_particle);
	void updateParticleCollision(size_t itr);
	
	sf::RenderWindow window = sf::RenderWindow (sf::VideoMode(K_WINDOWXY.x, K_WINDOWXY.y), "Particles");
	sf::Vector2u windowSize = window.getSize();

	std::vector<Particle*> m_vParticles;	// vector to store all particles

	std::vector<std::thread> m_vThreads;

};

#endif