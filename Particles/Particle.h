#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Particle {
public:
	Particle(float startX, float startY);

	sf::CircleShape getShape();
	void setParticlePosition(float posX, float posY);
private:
	sf::CircleShape particleShape;
	sf::Vector2f particlePosition;
};


#endif