#include "Screen.hpp"
#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <math.h>


Screen::Screen(void) {
    // Create a graphical text to display

    if (!font.loadFromFile("images/Font.otf")) {
        return;
    }

    width = 1024;
    height = 768;
}
