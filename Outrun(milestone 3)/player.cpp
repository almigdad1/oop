#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>
#include <iostream>
#include "Player.hpp"


Player::Player() {
    speed = 0.0f;
    height = 43;
    width = 40;
    maxOffroadSpeed = 150.0f;
    maxForwardSpeed = 300.0f;
    maxBackwardSpeed = -200.0f;

    y = 1500;
    z = 0.0f;
    x = 0.0f;

    speedIdlingResistance = -.8f;
    speedOffroadResistance = -1.0f;
    speedAcceleration = .4f;
    speedBraking = -2.0f;
}

void Player::createSprite(const Screen *screen) {

    sf::Texture playerTexture;
    std::string filePath ="images/mercedesspritesheets.png";
    playerTexture.loadFromFile(filePath);
    playerTexture.setSmooth(true);

    sprite.setTexture(playerTexture);

    sprite.setTextureRect(sf::IntRect(407, 0, width, height));
    sprite.setPosition(screen->width/2 - (width/2), 500);
    sprite.setScale(3, 3);
}

void Player::turnRight(const float turnWeight) {
    x += turnWeight;

    sprite.setTextureRect(sf::IntRect(407 + height, 0, width, height));
}

void Player::turnLeft(const float turnWeight) {
    x -= turnWeight;

    sprite.setTextureRect(sf::IntRect(407 - height, 0, width, height));
}

void Player::steerStraight(void) {
    sprite.setTextureRect(sf::IntRect(407, 0, width, height));
}

bool Player::isDrivingForward(void) {
    return speed > 0.0f;
}
bool Player::hasReachedMaxForwardSpeed(void) {
    return speed >= maxForwardSpeed;
}

bool Player::isDrivingBackward(void) {
    return speed < 0.0f;
}

bool Player::hasReachedMaxBackwardSpeed(void) {
    return speed <= maxBackwardSpeed;
}

bool Player::isStopped(void) {
    return !fabs(speed);
}

void Player::perLoopIdlingResistance() {

    if(isDrivingForward() && speed < speedAcceleration) {
        speed = 0.0f;
    }
    else if(isDrivingForward()) {
        speed += speedIdlingResistance;
    }
    else if(isDrivingBackward() && speed > -speedAcceleration) {
        speed  = 0.0f;
    }
    else if(isDrivingBackward()) {
        speed -= speedIdlingResistance;
    }
}


void Player::perLoopForwardBraking(void) {
    speed += speedBraking;
}

void Player::perLoopBackwardBraking(void) {
    speed -= speedBraking;
}

void Player::perLoopBackwardAcceleration(void) {
    speed -= speedAcceleration;
}

void Player::perLoopForwardAcceleration(void) {
    speed += speedAcceleration;
}


void Player::perLoopForwardAccelerationOffroad(void) {
    //player max speed offroad

    y = 1500;

    if(speed > maxOffroadSpeed) {
        speed += speedOffroadResistance;
    }
    else {
        perLoopForwardAcceleration();
    }
}
