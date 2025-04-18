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
		//setIsCollidingWithScreen(true);
	}
	else if ((getParticlePosition().x - getRadius()*2) <= 0)
	{
		// Left
		bounceOffScreen(Helpers::getCollisionAngle("Left"));
		//setIsCollidingWithScreen(true);
	}

	// Screen top and bottom collision
	if ((getParticlePosition().y + getRadius()) >= K_WINDOWXY.y)
	{
		// Bottom
		bounceOffScreen(Helpers::getCollisionAngle("Down")); 
		//setIsCollidingWithScreen(true);
	}
	else if ((getParticlePosition().y - getRadius()*2) <= 0)
	{
		// Top
		bounceOffScreen(Helpers::getCollisionAngle("Up"));	// OR DOWNRIGHT
		//setIsCollidingWithScreen(true);
	}
	//else {
	//	//setIsCollidingWithScreen(false);
	//}
}

void Particle::bounceOffScreen(sf::Vector2i dir)
{
	setDirection(dir);	// OR UPRIGHT
	//setVelocity({dir.x * getSpeed(), dir.y * getSpeed()});
	//moveParticle();
}

sf::CircleShape Particle::getShape()
{
	return particleShape;
}

sf::Vector2f Particle::getVelocity()
{
	float velocityX = getSpeed() * getDirection().x;
	float velocityY = getSpeed() * getDirection().y;
	return {velocityX, velocityY};
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
