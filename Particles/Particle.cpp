#include "Particle.h"

Particle::Particle(float startX, float startY)
{
	// these are maybe default values?
	particleShape.setRadius(10.f);
	particleShape.setFillColor(sf::Color::White);
	setParticlePosition(startX, startY);
	particleShape.setOrigin(particleShape.getRadius(), particleShape.getRadius()); // Set origin to centre
}

void Particle::moveParticle()
{
	float movePosX = particlePosition.x + direction.x;
	float movePosY = particlePosition.y + direction.y;

	setParticlePosition(movePosX, movePosY);
}

void Particle::collideWithScreen()
{
	if (particlePosition.x = K_WINDOWXY.x)
	{

	}
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

void Particle::setColour(sf::Color _colour)
{
	colour = _colour;
	particleShape.setFillColor(colour);
}

void Particle::setRadius(float _radius)
{
	radius = _radius;
	particleShape.setRadius(radius);
}
