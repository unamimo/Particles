#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.h"

class Particle {
public:
	Particle(float startX, float startY);

	void moveParticle();
	void collideWithScreen();

	sf::CircleShape getShape();
	sf::Vector2f getParticlePosition() { return particlePosition; }
	sf::Color getColour() { return colour; }
	float getRadius() { return radius; }
	float getVelocity() { return velocity; }
	sf::Vector2i getDirection() { return direction; }
	bool getIsCollidingWithScreen() { return isCollidingWithScreen; }

	void setParticlePosition(float posX, float posY);
	//void setColour(sf::Color _colour) { colour = _colour; }
	void setColour(sf::Color _colour);
	//void setRadius(float _radius) { radius = _radius; }
	void setRadius(float _radius);
	void setVelocity(float _velocity) { velocity = _velocity; }
	void setDirection(sf::Vector2i _direction) { direction = _direction; }
	void setIsCollidingWithScreen(bool _isCollidingWithScreen) { isCollidingWithScreen = _isCollidingWithScreen;  }
private:
	sf::CircleShape particleShape;
	sf::Vector2f particlePosition;
	sf::Color colour;
	float radius;
	float velocity;
	sf::Vector2i direction;	// end position?
	bool isCollidingWithScreen = false;
};


#endif