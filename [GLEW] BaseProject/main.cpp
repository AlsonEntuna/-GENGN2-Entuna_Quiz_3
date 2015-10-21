/*!
Linux compile

g++ Camera.cpp ModelTransform.cpp Mesh.cpp Shader.cpp GameObject.cpp Base.cpp SCV.cpp Abstraction.cpp main.cpp -o run.exe -lGL -lGLEW -lsfml-graphics -lsfml-window -lsfml-system && ./run.exe

Windows compile

g++ Camera.cpp ModelTransform.cpp Mesh.cpp Shader.cpp GameObject.cpp Base.cpp SCV.cpp Abstraction.cpp main.cpp -o run.exe -IC:/glew/include -LC:/glew/lib -IC:/sfml/include -LC:/sfml/lib -IC:/glm -lsfml-window -lsfml-graphics -lsfml-system -lglew32 -lopengl32 -lglu32 && run.exe

Questions 1-3 -> SCV update()
Questions 4-5 -> Base.h
Questions 6-8 -> main
*/

#include <glm/glm.hpp>
#include "Abstraction.h"
#include "SCV.h"
#include "Base.h"
#include "Camera.h"
#include <vector>

using namespace std;


int main()
{
    Abstraction abstraction(30,(char*)"Entuna - G-ENGN2 Quiz 3");
    Camera camera(glm::vec3(0,0,3),70.0f, 400.0f/300.0f,0.01f,1000.0f);

	// SCVs
	SCV scv1(0);
	SCV scv2(1);
	SCV scv3(2);
	SCV scv4(3);
	Base base;

	scv1.assignBase(&base);
	scv2.assignBase(&base);
	scv3.assignBase(&base);
	scv4.assignBase(&base);// assigns the base to the SCV

	// Set SVCs
	scv1.setX(0); scv1.setY(0); scv1.setZ(-10);
	scv2.setX(0); scv2.setY(0); scv2.setZ(-10);
	scv3.setX(0); scv3.setY(0); scv3.setZ(-10);
	scv4.setX(0); scv4.setY(0); scv4.setZ(-10);
	// Set base
	base.setX(0); base.setY(0); base.setZ(-9);

	sf::Thread thread1(&SCV::update, &scv1);
	sf::Thread thread2(&SCV::update, &scv2);
	sf::Thread thread3(&SCV::update, &scv3);
	sf::Thread thread4(&SCV::update, &scv4);

    //6-7. create 4 threads that will run the SCV's update. Create 4 SCVs and 1 Base
    //    to use for the update and draws. Station the SVCs at depth -10 and the 
    //    Base at -9 but all objects should spawn at the center of the screen(0,0). 

	thread1.launch();

	int counter = 1;
    while (abstraction.isRunning())
	{
        abstraction.checkPollEvents();
        abstraction.clear();

        //8. Create a mechaism for purchasing an SCV
        //    Should the minerals be equal to or more than 150 and there are less than 4 SCVS
        //    purchase an SCV and let it start mining. Make sure the purchase requests a lock
        //    so SCVs deposit the minerals properly.
		if (base.getMineralCount() >= 20 && counter <= 4)
		{
			counter++;
			cout << "Launching!!!" << endl;
			if (counter == 2) thread2.launch();
			if (counter == 3) thread3.launch();
			if (counter == 4) thread4.launch();
			base.addMinerals(-20);
			
		}

		scv1.draw(camera);
		scv2.draw(camera);
		scv3.draw(camera);
		scv4.draw(camera);
		base.draw(camera);
        abstraction.display();
    }
    return 0;
}//end func
