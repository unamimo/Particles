#include "Game.h"

Game::Game()
{
    window.setFramerateLimit(60);
}

void Game::run() {
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
//equivelent of 'init' function
void Game::render() {
    window.clear();


    // Draw Loop
    /////////////////////////
    window.draw(m_particle.getShape());
    window.draw(m_particle2.getShape());
    ////////////////////////


    window.display();
}

void Game::createParticle(sf::Color colour, sf::Vector2f position, float radius, float velocity)
{
    m_particle.setColour(colour);
    m_particle.setParticlePosition(position.x, position.y);
    m_particle.setRadius(radius);
    m_particle.setVelocity(velocity);
}
