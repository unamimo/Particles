#include "Game.h"

Game::Game()
{
    window.setFramerateLimit(60);
}

void Game::run() {
    init();

    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

//handle movement
void Game::update() {
    for (size_t i = 0; i < m_vParticles.size(); i++)
    {
        m_vParticles[i].moveParticle();
        m_vParticles[i].collideWithScreen();

        // for checking collission between two particles
        for (size_t j = 0; j < m_vParticles.size(); j++)
        {
            if (i != j) // don't compare the the same element
            {
                checkParticleCollision(m_vParticles[i], m_vParticles[j]);
            }
        }
    }
}

//handle drawing
void Game::render() {
    window.clear();


    // Draw Loop
    /////////////////////////
    for (size_t i = 0; i < m_vParticles.size(); i++)
    {
        window.draw(m_vParticles[i].getShape());
    }
    ////////////////////////


    window.display();
}

void Game::init()
{
    for (size_t i = 0; i < K_NUMPARTICLES; i++)
    {
        //random co-oordinates
        // convert int to float now, but will later on accept floats
        sf::Vector2f randPos = { static_cast<float>(Helpers::getRandomNum(0, K_WINDOWXY.x)),  static_cast<float>(Helpers::getRandomNum(0, K_WINDOWXY.y)) };
        float randomSpeed = Helpers::getRandomNum(K_PARTICLESPEEDLOWER, K_PARTICLESPEEDUPPER);

        createParticle(Helpers::getRandomColour(), randPos, K_PARTICLERADIUS, randomSpeed, Helpers::getRandomDirection());
    }
}

void Game::createParticle(sf::Color colour, sf::Vector2f startPos, float radius, float speed, sf::Vector2i direction)
{
    // set particle start pos to middle of screen by default
    Particle m_particle = Particle(windowSize.x / 2, windowSize.y / 2);

    m_particle.setColour(colour);
    m_particle.setParticlePosition(startPos.x, startPos.y);
    m_particle.setRadius(radius);
    m_particle.setSpeed(speed);
    m_particle.setDirection(direction);
    m_particle.setOrigin({ radius, radius });
    m_particle.setVelocity({ speed * direction.x,  speed * direction.y });

    m_vParticles.push_back(m_particle);
}

//https://www.jeffreythompson.org/collision-detection/circle-circle.php
void Game::checkParticleCollision(Particle& particle1, Particle& particle2)
{
    float distX = particle1.getParticlePosition().x - particle2.getParticlePosition().x;
    float distY = particle1.getParticlePosition().y - particle2.getParticlePosition().y;
    float distance = sqrt((distX * distX) + (distY * distY));
    float combinedRadii = (particle1.getRadius() + particle2.getRadius());

    // collision resolution
    // https://www.101computing.net/elastic-collision-in-a-pool-game/
    float dist = (distX * distX) + (distY * distY);
    sf::Vector2f differenceInVelocity = (particle1.getVelocity() - particle2.getVelocity());
    float dot = distX * differenceInVelocity.x + distY * differenceInVelocity.y;

    float scalar = dot / dist;
    sf::Vector2f collision = { scalar * distX, scalar * distY };

    if (distance < (combinedRadii))
    {
        particle1.setVelocity(particle1.getVelocity() - collision);
        particle2.setVelocity(particle2.getVelocity() - collision);
    }
}