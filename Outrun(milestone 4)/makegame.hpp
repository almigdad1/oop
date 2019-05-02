#pragma once
#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
class game
{
    public:
    const int width = 1024;
    const int height = 768;
    const int roadW = 2000;
    const int segL = 200;    // segment length
    float camD = 0.89f; // camera depth


    void drawQuad(RenderWindow& ,Color , int, int, int, int, int, int);

    void createWindow();
};

// Milestone 4 part, added these from the example code and used them.
struct event_listener
{
    // Window events
    virtual void on_close() { }

    // Keyboard events
    virtual void on_key_press(sf::Event::KeyEvent) { }
    virtual void on_key_release(sf::Event::KeyEvent) { }
};

struct event_source
{
    event_source(sf::Window& w)
    : window(&w)
    { }

    void
    listen(event_listener& l)
    {
        listeners.push_back(&l);
    }

    // Notify listeners of queued events.
    void
    poll()
    {
        sf::Event e;
        while (window->pollEvent(e))
            process(e);
    }

    // Notify listeners of a single event.
    void process(sf::Event const& e)
    {
        switch (e.type) {
            case sf::Event::Closed:
                return notify([e](event_listener* l) { l->on_close(); });
            case sf::Event::KeyPressed:
                return notify([e](event_listener* l) { l->on_key_press(e.key); });
            default:
                break;
        }
    }

    template<typename F>
    void notify(F fn)
    {
        for (event_listener* l : listeners)
            fn(l);
    }

    // The window that we can poll for events.
    sf::Window* window;

    // A list of listeners to notify about particular
    // events.
    std::vector<event_listener*> listeners;
};
//Declare points
struct point : event_listener
{
    int x, y;
};


struct debug_listener : event_listener
{
  debug_listener(game& a)
    : app(&a)
  { }

  void on_close() override
  {
    std::cerr << "closing...\n";
  }



  game* app;
};
