#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

class Particle {
public:
	Particle(float startX, float startY);

	sf::CircleShape getShape();
	sf::Vector2f getParticlePosition() { return particlePosition; }
	sf::Color getColour() { return colour; }
	float getRadius() { return radius; }
	float getVelocity() { return velocity; }

	void setParticlePosition(float posX, float posY);
	//void setColour(sf::Color _colour) { colour = _colour; }
	void setColour(sf::Color _colour);
	//void setRadius(float _radius) { radius = _radius; }
	void setRadius(float _radius);
	void setVelocity(float _velocity) { velocity = _velocity; }
private:
	sf::CircleShape particleShape;
	sf::Vector2f particlePosition;
	sf::Color colour;
	float radius;
	float velocity;

	// associate colours with numbers to get a random value
	std::map<sf::Color, int> colourMap = {
		{sf::Color::Red, 0},
		{sf::Color::Blue, 1},
		{sf::Color::Green, 2},
		{sf::Color::Yellow, 3},
		{sf::Color::Magenta, 4},
	};
};


#endif