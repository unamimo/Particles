#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.h"
#include "Helpers.h"

class Particle {
public:
	Particle(float startX, float startY);

	void moveParticle();
	void collideWithScreen();
	void bounceOffScreen(sf::Vector2i dir);

	sf::CircleShape getShape();
	sf::Vector2f getParticlePosition() { return particlePosition; }
	sf::Color getColour() { return colour; }
	float getRadius() { return radius; }
	sf::Vector2f getVelocity();
	float getSpeed() { return speed; }
	sf::Vector2i getDirection() { return direction; }
	//bool getIsCollidingWithScreen() { return isCollidingWithScreen; }

	void setParticlePosition(float posX, float posY);
	//void setColour(sf::Color _colour) { colour = _colour; }
	void setColour(sf::Color _colour);
	//void setRadius(float _radius) { radius = _radius; }
	void setRadius(float _radius);
	void setVelocity(sf::Vector2f _velocity) { velocity = _velocity; }
	void setSpeed(float _speed) { speed = _speed; }
	void setDirection(sf::Vector2i _direction) { direction = _direction; }
	//void setIsCollidingWithScreen(bool _isCollidingWithScreen) { isCollidingWithScreen = _isCollidingWithScreen;  }
private:
	sf::CircleShape particleShape;
	sf::Vector2f particlePosition;
	sf::Color colour;
	float radius;
	sf::Vector2f velocity;			// speed * direction
	float speed;
	sf::Vector2i direction;
	//bool isCollidingWithScreen = false;
};


#endif