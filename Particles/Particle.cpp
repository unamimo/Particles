#include "Particle.h"

Particle::Particle(float startX, float startY)
{
	particleShape.setRadius(10.f);
	particleShape.setFillColor(sf::Color::White);
	setParticlePosition(startX, startY);
	particleShape.setOrigin(particleShape.getRadius(), particleShape.getRadius()); // Set origin to centre
}

void Particle::moveParticle()
{
	float movePosX = getParticlePosition().x + (getVelocity().x );
	float movePosY = getParticlePosition().y + (getVelocity().y );

	setParticlePosition(movePosX, movePosY);
}

void Particle::collideWithScreen()
{
	// Screen left and right collision
	if ((getParticlePosition().x + getRadius()) >= K_WINDOWXY.x)
	{
		// Right
		bounceOffScreen(Helpers::getCollisionAngle("Right")); 
	}
	else if ((getParticlePosition().x - getRadius()*2) <= 0)
	{
		// Left
		bounceOffScreen(Helpers::getCollisionAngle("Left"));
	}

	// Screen top and bottom collision
	if ((getParticlePosition().y + getRadius()) >= K_WINDOWXY.y)
	{
		// Bottom
		bounceOffScreen(Helpers::getCollisionAngle("Down")); 
	}
	else if ((getParticlePosition().y - getRadius()*2) <= 0)
	{
		// Top
		bounceOffScreen(Helpers::getCollisionAngle("Up"));
	}
}

void Particle::bounceOffScreen(sf::Vector2i dir)
{
	setDirection(dir);
	setVelocity({dir.x * getSpeed(), dir.y * getSpeed()});
}

sf::CircleShape Particle::getShape()
{
	return particleShape;
}

sf::Vector2f Particle::getVelocity()
{
	return velocity;
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

void Particle::setOrigin(sf::Vector2f _origin)
{
	origin = _origin;
	particleShape.setOrigin(origin.x, origin.y);
}
