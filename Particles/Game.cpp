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
    createParticle(sf::Color::Green, { 200, 100 }, 10.f, 20.f);
    createParticle(sf::Color::Blue, { 400, 239 }, 30.f, 20.f);
    createParticle(sf::Color::Red, { 100, 500 }, 5.f, 20.f);
}

void Game::createParticle(sf::Color colour, sf::Vector2f position, float radius, float velocity)
{
    // set particle start pos to middle of screen by default
    Particle m_particle = Particle(windowSize.x / 2, windowSize.y / 2);

    m_particle.setColour(colour);
    m_particle.setParticlePosition(position.x, position.y);
    m_particle.setRadius(radius);
    m_particle.setVelocity(velocity);

    m_vParticles.push_back(m_particle);
}
