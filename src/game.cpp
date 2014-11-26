#include "game.h"

void Game::quit() {
    run = false;
    window.close();
}

void Game::handle_key(sf::Keyboard::Key k) {
    switch (k) {
        case sf::Keyboard::Escape:
            quit();
            break;
        default:
            break;

    }
}

Game::Game() : window(sf::VideoMode(800,600),"Break") {
    run = true;
    sheet.loadFromFile("res/sheet.png");

    paddle = sf::Sprite(sheet,sf::IntRect(0,0,16,4));
    paddle.setScale(4.0,4.0);

    objects.push_back(&paddle);
}

void Game::events() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                quit();
                break;
            case sf::Event::KeyPressed:
                handle_key(event.key.code);
                break;
            default:
                break;
        }
    }
}

void Game::update() {

}

void Game::draw() {
    window.clear(sf::Color(200,200,200,255)); 
    for (sf::Sprite* item : objects) {
        window.draw(*item);
    }
    window.display();
}

bool Game::running() {
    return run;
}
