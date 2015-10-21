#include "Abstraction.h"

Abstraction::Abstraction(int fps,char* title){
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;

    window.create(sf::VideoMode(800, 600), title, sf::Style::Default, settings);
    window.setPosition(sf::Vector2i(0,0));

    //initialize GLEW
    GLenum status = glewInit();
    if(status != GLEW_OK)
        std::cout << "ERROR" << std::endl;

    timePerFrame = fps/60*1000;
    running = true;
}//end func

void Abstraction::clear(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
}

void Abstraction::checkPollEvents(){
    sf::Event event;
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            // end the program
            running = false;
        }else if (event.type == sf::Event::Resized){
            // adjust the viewport when the window is resized
            glViewport(0, 0, event.size.width, event.size.height);
        }//end else if
    }//end while
}//end func

void Abstraction::display(){
    window.display();
    //FPS regulator
    sf::sleep(sf::milliseconds(timePerFrame-
        clock.getElapsedTime().asMilliseconds()));
    clock.restart();
}//end func

bool Abstraction::isRunning(){
    return running;
}//end func
