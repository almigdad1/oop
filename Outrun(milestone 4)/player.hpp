#ifndef Player_hpp
#define Player_hpp
#include "Screen.hpp"
#include <stdio.h>
#include <SFML/Graphics.hpp>



class Player {
public:
    Player(void);
    void createSprite(const Screen *screen);
    void turnRight(const float turnWeight);
    void turnLeft(const float turnWeight);
    void steerStraight(void);
    bool isDrivingForward(void);
    bool hasReachedMaxForwardSpeed(void);
    bool isDrivingBackward(void);
    bool isStopped(void);
    bool hasReachedMaxBackwardSpeed(void);

    void perLoopIdlingResistance(void);
    void perLoopForwardBraking(void);
    void perLoopBackwardBraking(void);
    void perLoopBackwardAcceleration(void);
    void perLoopForwardAcceleration(void);
    void perLoopForwardAccelerationOffroad(void);

    sf::Sprite sprite;
    int height;
    int width;
    float x;
    float y;
    float z;
    float speed;
    float maxForwardSpeed;
    float maxBackwardSpeed;
    float maxOffroadSpeed;
private:

    float speedIdlingResistance;
    float speedOffroadResistance;
    float speedAcceleration;
    float speedBraking;
};

#endif /* Player_hpp */
