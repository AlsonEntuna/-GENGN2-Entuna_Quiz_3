#ifndef ABSTRACTION_H
#define ABSTRACTION_H

#include <SFML/Window.hpp>
#include <iostream>
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

class Abstraction{
public:
    Abstraction(int fps,char* title);
    void checkPollEvents();
    void clear();
	void display();
    bool isRunning();
protected:
private:
    sf::ContextSettings settings;
    sf::Window window;
    float timePerFrame;
    sf::Clock clock;
    bool running;
};

#endif
