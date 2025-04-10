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
	// Screen left and right collision
	if ((particlePosition.x + radius) == K_WINDOWXY.x)
	{
		setParticlePosition(particlePosition.x - 1, particlePosition.y);
	}
	else if ((particlePosition.x - radius*2) == 0)
	{
		setParticlePosition(particlePosition.x + 1, particlePosition.y);
	}

	// Screen top and bottom collision
	if ((particlePosition.y + radius) == K_WINDOWXY.y)
	{
		setParticlePosition(particlePosition.x, particlePosition.y - 1);
	}
	else if ((particlePosition.y - radius*2) == 0)
	{
		setParticlePosition(particlePosition.x, particlePosition.y + 1);
	}
}

void Particle::collideWithParticles()
{
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
