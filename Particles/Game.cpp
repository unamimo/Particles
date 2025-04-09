#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Partcles"), windowSize(window.getSize()), m_particle(windowSize.x/2, windowSize.y/2) {
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
void Game::render() {
    window.clear();


    // Draw Loop
    /////////////////////////
    window.draw(m_particle.getShape());
    ////////////////////////


    window.display();
}