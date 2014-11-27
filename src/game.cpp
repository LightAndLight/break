#include "game.h"
#include "paddle.h"
#include "ball.h"

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
            paddle.setDir(LEFT);
            break;

        case sf::Keyboard::Right:
            paddle.setDir(RIGHT);
            break;

        default:
            break;

    }
}

void Game::key_release(sf::Keyboard::Key k) {
    switch (k) {
        case sf::Keyboard::Left:
            if (paddle.getDir() == LEFT) paddle.setDir(NONE);
            break;

        case sf::Keyboard::Right:
            if (paddle.getDir() == RIGHT) paddle.setDir(NONE);
            break;

        default:
            break;

    }
}

Game::Game() : window(sf::VideoMode(800,600),"Break") {
    run = true;
    sheet.loadFromFile("res/sheet.png");

    paddle = Paddle(sheet,sf::IntRect(0,0,16,4));
    paddle.setScale(4.0,4.0);
    paddle.setPosition(400-paddle.width()/2,
                       600-paddle.height()-10);

    ball = Ball(sheet,sf::IntRect(16,0,4,4));
    ball.setScale(4.0,4.0);
    ball.setPosition(400-ball.width()/2,300-ball.height()/2);
    ball.setDir(sf::Vector2f(1.0,-0.25));

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

    int paddleSpeed = paddle.getSpeed();

    switch (paddle.getDir()) {
        case LEFT:
            if (paddle.left() - paddleSpeed*dt > 0.0) 
                paddle.move(-paddleSpeed*dt,0.0);
            break;

        case RIGHT:
            if (paddle.left() + paddleSpeed*dt 
                    < 800.0 - paddle.width())
                paddle.move(paddleSpeed*dt,0.0);
            break;

        case NONE:
            break;
    }
    
    sf::Vector2f ballDir = ball.getDir();
    int ballSpeed = ball.getSpeed();
    ball.move(ballDir.x*ballSpeed*dt,ballDir.y*ballSpeed*dt);

    last_call = recent_call;
}

void Game::collisions() {
    if (ball.top() <= 0) {
        ball.reflectX();
    }

    if (ball.top() > 600 - ball.height()) {
        ball.reflectX();
    }

    if (ball.left() <= 0) {
        ball.reflectY();
    }

    if (ball.left() > 800 - ball.width()) {
        ball.reflectY();
    }
}

void Game::draw() {
    window.clear(sf::Color(200,200,200,255)); 

    paddle.draw(window);
    ball.draw(window);

    window.display();
}

bool Game::running() {
    return run;
}
