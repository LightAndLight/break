#include "game.h"

void Game::quit() {
    run = false;
    window.close();
}

void Game::key_press(sf::Keyboard::Key k) {
    switch (k) {
        case sf::Keyboard::Escape:
            quit();
            break;

        case sf::Keyboard::Left:
            paddle_dir = LEFT;
            break;

        case sf::Keyboard::Right:
            paddle_dir = RIGHT;
            break;

        default:
            break;

    }
}

void Game::key_release(sf::Keyboard::Key k) {
    switch (k) {
        case sf::Keyboard::Left:
            if (paddle_dir == LEFT) paddle_dir = NONE;
            break;

        case sf::Keyboard::Right:
            if (paddle_dir == RIGHT) paddle_dir = NONE;
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
    paddle.setPosition(400-paddle.getGlobalBounds().width/2,
                       600-paddle.getGlobalBounds().height-10);
    paddle_dir = NONE;
    paddle_speed = 400;

    objects.push_back(&paddle);

    last_call = clock.getElapsedTime();
}

void Game::events() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                quit();
                break;

            case sf::Event::KeyPressed:
                key_press(event.key.code);
                break;

            case sf::Event::KeyReleased:
                key_release(event.key.code);
                break;

            default:
                break;
        }
    }
}

void Game::update() {
    sf::Time recent_call = clock.getElapsedTime();
    float dt = (recent_call - last_call).asSeconds();

    switch (paddle_dir) {
        case LEFT:
            if (paddle.getGlobalBounds().left - paddle_speed*dt > 0.0) 
                paddle.move(-paddle_speed*dt,0.0);
            break;

        case RIGHT:
            if (paddle.getGlobalBounds().left + paddle_speed*dt 
                    < 800.0 - paddle.getGlobalBounds().width)
                paddle.move(paddle_speed*dt,0.0);
            break;

        case NONE:
            break;
    }

    last_call = recent_call;
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
