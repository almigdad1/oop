#include <SFML/Graphics.hpp>
#include <makegame.hpp>

using namespace sf;


int main()
{
    game app;
    // Create a debugger
    debug_listener debug(app);


    app.createWindow();
  return 0;
}
