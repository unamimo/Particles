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
	float movePosX = getParticlePosition().x + getDirection().x;
	float movePosY = getParticlePosition().y + getDirection().y;

	setParticlePosition(movePosX, movePosY);
}

void Particle::collideWithScreen()
{
	// Screen left and right collision
	if ((particlePosition.x + radius) == K_WINDOWXY.x)
	{
		// Right
		//setParticlePosition(particlePosition.x - 1, particlePosition.y);
		setDirection(K_UPLEFT); // OR K_DOWNRIGHT?
		moveParticle();
		setIsCollidingWithScreen(true);
	}
	else if ((particlePosition.x - radius*2) == 0)
	{
		// Left
		//setParticlePosition(particlePosition.x + 1, particlePosition.y);
		setDirection(K_UPRIGHT);	// OR K_DOWNRIGHT?
		moveParticle();
		setIsCollidingWithScreen(true);
	}

	// Screen top and bottom collision
	if ((particlePosition.y + radius) == K_WINDOWXY.y)
	{
		// Bottom
		//setParticlePosition(particlePosition.x, particlePosition.y - 1);
		setDirection(K_UPLEFT);	// OR UPRIGHT
		moveParticle();
		setIsCollidingWithScreen(true);
	}
	else if ((particlePosition.y - radius*2) == 0)
	{
		// Top
		//setParticlePosition(particlePosition.x, particlePosition.y + 1);
		setDirection(K_DOWNLEFT);	// OR DOWNRIGHT
		moveParticle();
		setIsCollidingWithScreen(true);
	}
	else {
		setIsCollidingWithScreen(false);
	}
}

void Particle::bounceOffScreen(sf::Vector2i dir)
{
	setDirection(dir);	// OR UPRIGHT
	moveParticle();
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
