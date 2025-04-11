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
    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    //    rightPaddle.moveUp();
    //}
    //else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) {
    //    rightPaddle.moveDown();
    //}
    for (size_t i = 0; i < m_vParticles.size(); i++)
    {
        m_vParticles[i].moveParticle();
        m_vParticles[i].collideWithScreen();

        Particle particle1 = m_vParticles[i];
        Particle particle2 = m_vParticles[i + 1];
        collideWithParticles(particle1, particle2);
    }
}

//handle drawing
void Game::render() {
    window.clear();


    // Draw Loop
    /////////////////////////
    //window.draw(m_particle.getShape());
    //window.draw(m_particle2.getShape());
    for (size_t i = 0; i < m_vParticles.size(); i++)
    {
        window.draw(m_vParticles[i].getShape());
    }
    ////////////////////////


    window.display();
}

void Game::init()
{
    //createParticle(sf::Color::Green, { 200, 100 }, 10.f, 20.f);
    //createParticle(sf::Color::Blue, { 400, 239 }, 30.f, 20.f);
    //createParticle(sf::Color::Red, { 100, 500 }, 5.f, 20.f);

    for (size_t i = 0; i < K_NUMPARTICLES; i++)
    {
        //random co-oordinates
        // convert int to float now, but will later on accept floats
        sf::Vector2f randPos = { static_cast<float>(getRandomNum(0, K_WINDOWXY.x)),  static_cast<float>(getRandomNum(0, K_WINDOWXY.y)) };

        createParticle(getRandomColour(), randPos, K_PARTICLERADIUS, K_PARTICLEVELOCITY, getRandomDirection());
    }
}

void Game::createParticle(sf::Color colour, sf::Vector2f startPos, float radius, float velocity, sf::Vector2i direction)
{
    // set particle start pos to middle of screen by default
    Particle m_particle = Particle(windowSize.x / 2, windowSize.y / 2);

    m_particle.setColour(colour);
    m_particle.setParticlePosition(startPos.x, startPos.y);
    m_particle.setRadius(radius);
    m_particle.setVelocity(velocity);
    m_particle.setDirection(direction);

    m_vParticles.push_back(m_particle);
}

//https://www.jeffreythompson.org/collision-detection/circle-circle.php
void Game::collideWithParticles(Particle particle1, Particle particle2)
{
    // check one particle to see if it collides with any other paricle in the array
    //for (size_t i = 0; i < m_vParticles.size(); i++)
    //{
    //    Particle circle1 = m_vParticles[i];
    //    Particle circle2;


    //}

    //sf::Vector2f otherPos;
    //sf::Vector2f otherPos;

    float distX = particle1.getParticlePosition().x - particle2.getParticlePosition().x;
    float distY = particle1.getParticlePosition().y - particle2.getParticlePosition().y;
    float distance = sqrt((distX * distX) + (distY * distY));

    if (distance <= particle1.getRadius() + particle2.getRadius())
    {
        particle1.setColour(sf::Color::Red);
        particle2.setColour(sf::Color::Red);
    }
}

int Game::getRandomNum(int lowerRange, int upperRange)
{
    //generate random number that only regenerates on new function call
    //float randomNum = (rand() % upperRange) + 1;

    //https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(lowerRange, upperRange); // distribution

    return dist(rng);
}

sf::Color Game::getRandomColour()
{
    int colourKey = getRandomNum(0, colourMap.size() - 1);

    return colourMap.at(colourKey);
}

sf::Vector2<int> Game::getRandomDirection()
{
    int directionKey = getRandomNum(0, directionMap.size() - 1);

    return directionMap.at(directionKey);
}
