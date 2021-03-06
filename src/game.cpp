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
            paddle.setMotion(sf::Vector2f(-400,0));
            break;

        case sf::Keyboard::Right:
            paddle.setMotion(sf::Vector2f(400,0));
            break;

        default:
            break;

    }
}

void Game::key_release(sf::Keyboard::Key k) {
    switch (k) {
        case sf::Keyboard::Left:
            if (paddle.getMotion().x == -400) paddle.setMotion(sf::Vector2f(0,0));
            break;

        case sf::Keyboard::Right:
            if (paddle.getMotion().x == 400) paddle.setMotion(sf::Vector2f(0,0));
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

    ball = Ball(sheet,sf::IntRect(16,0,4,4));
    ball.setScale(4.0,4.0);

    init();
}

void Game::init() {
    paddle.setPosition(400-paddle.width()/2,600-paddle.height()-10);

    ball.setPosition(400-ball.width()/2,300-ball.height()/2);
    ball.setMotion(sf::Vector2f(0,1));
    ball.setSpeed(300);

    Brick brick(sheet,sf::IntRect(0,4,12,8));
    brick.setScale(4.0,4.0);

    bricks.clear();

    for (int i = 0; i < 5; ++i) {
        std::vector<Brick> row;
        for (int j = 0; j < 8; ++j) {
            brick.setPosition(40+j*96,i*64);
            row.push_back(brick);
        }
        bricks.push_back(row);
    }

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
    dt = (recent_call - last_call).asSeconds();

    sf::Vector2f paddleMotion = paddle.getMotion();
    paddle.move(paddleMotion.x*dt,paddleMotion.y*dt);
   
    sf::Vector2f ballMotion = ball.getMotion();
    ball.move(ballMotion.x*dt,ballMotion.y*dt);

    last_call = recent_call;
}

void Game::collisions() {

    // ball and wall checking

    if (ball.top() <= 0) {
        ball.reflectX();
    }

    if (ball.top() > 600) {
        init();
    }

    if (ball.left() <= 0) {
        ball.reflectY();
    }

    if (ball.left() > 800 - ball.width()) {
        ball.reflectY();
    }

    // ball and brick collision - naive

    Bounded ballBB = ball.getBB();
    ballBB.move(ball.getMotion().x*dt,ball.getMotion().y*dt);

    for (std::vector<Brick>& row : bricks) {
        for (Brick& b : row) {
            Bounded brickBB = b.getBB();

            if (b.isVisible() && brickBB.intersects(ballBB)) {

                b.recieveHit();
                if (b.hitsRemaining() == 0) {
                    b.hide();
                }

                switch (brickBB.intersectingSide(ballBB)) {
                    case LEFT:
                        ball.reflectY();
                        break;
                    case RIGHT:
                        ball.reflectY();
                        break;
                    case TOP:
                        ball.reflectX();
                        break;
                    case BOTTOM:
                        ball.reflectX();
                        break;
                    default:
                        break;
                }
            }
        }
    }

    Bounded paddleBB = paddle.getBB();

    if (paddleBB.intersects(ballBB)) {
        sf::Vector2f ballMotion = ball.getMotion();
        sf::Vector2f paddleMotion = paddle.getMotion();

        float leftDist;
        float rightDist;
        float deflectFactor;

        switch (paddleBB.intersectingSide(ballBB)) {
            case LEFT:
                ball.reflectY();
                if (paddleMotion.x != 0) 
                    ball.setMotion(sf::Vector2f(ballMotion.x + paddleMotion.x,ballMotion.y));
                break;
            case RIGHT:
                ball.reflectY();
                if (paddleMotion.x != 0) 
                    ball.setMotion(sf::Vector2f(ballMotion.x + paddleMotion.x,ballMotion.y));
                break;
            case TOP:
                leftDist = ball.right() - paddle.left() - ball.width()/2;
                rightDist = paddle.right() - ball.left() - ball.width()/2;

                if (leftDist < rightDist) {
                    deflectFactor = (2/paddle.width())*leftDist - 1;
                } else if (rightDist < leftDist) {
                    deflectFactor = (2/paddle.width())*(paddle.width() - rightDist) - 1;
                } else {
                    deflectFactor = 0;
                }

                ball.setMotion(sf::Vector2f(ballMotion.x + deflectFactor*100,ballMotion.y));

                ball.reflectX();

                break;
            default:
                break;
        }
    }
}

void Game::draw() {
    window.clear(sf::Color(200,200,200,255)); 

    paddle.draw(window);
    ball.draw(window);
    for (std::vector<Brick> row : bricks) {
        for (Brick b : row) {
            if (b.isVisible()) {
                b.draw(window);
            }
        }
    }

    window.display();
}

bool Game::running() {
    return run;
}
