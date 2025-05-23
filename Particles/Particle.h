#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.h"
#include "Helpers.h"

class Particle {
public:
	Particle(float startX, float startY);

	void moveParticle();						// moves particles in a direction
	void collideWithScreen();					// checks collision against screen
	void bounceOffScreen(sf::Vector2i dir);		// handles collision resolution with screen

	sf::CircleShape getShape();
	sf::Vector2f getParticlePosition() { return particlePosition; }
	sf::Color getColour() { return colour; }
	float getRadius() { return radius; }
	sf::Vector2f getVelocity();
	float getSpeed() { return speed; }
	sf::Vector2i getDirection() { return direction; }

	void setParticlePosition(float posX, float posY);
	void setColour(sf::Color _colour);
	void setRadius(float _radius);
	void setOrigin(sf::Vector2f _origin);
	void setVelocity(sf::Vector2f _velocity) { velocity = _velocity; }
	void setSpeed(float _speed) { speed = _speed; }
	void setDirection(sf::Vector2i _direction) { direction = _direction; }
private:
	sf::CircleShape particleShape;
	sf::Vector2f particlePosition;
	sf::Color colour;
	float radius;
	sf::Vector2f origin;
	sf::Vector2f velocity;			// speed * direction
	float speed;
	sf::Vector2i direction;
};


#endif