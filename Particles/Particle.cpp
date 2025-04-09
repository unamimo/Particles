#include "Particle.h"

Particle::Particle(float startX, float startY)
{
	particleShape.setRadius(10.f);
	particleShape.setFillColor(sf::Color::Blue);
	setParticlePosition(startX, startY);
	particleShape.setOrigin(particleShape.getRadius(), particleShape.getRadius()); // Set origin to centre
}

sf::CircleShape Particle::getShape()
{
	return particleShape;
}

void Particle::setParticlePosition(float posX, float posY)
{
	particlePosition.x = posX;
	particlePosition.y = posY;
	particleShape.setPosition(particlePosition);
}
