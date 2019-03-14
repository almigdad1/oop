
#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>
using namespace sf;
class game
{
    public:
    const int width = 1024;
    const int height = 768;
    const int roadW = 2000;
    const int segL = 200;    // segment length
    float camD = 0.84; // camera depth


    void drawQuad(RenderWindow& ,Color , int, int, int, int, int, int);

    void createWindow();
};

