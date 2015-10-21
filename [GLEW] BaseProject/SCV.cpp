#include "SCV.h"

sf::Mutex SCV::mutex;

SCV::SCV()
{
	currentCommand = Command::Gather;
}

SCV::SCV(int dir)
{
	currentCommand = Command::Gather;
	init(dir);
}

void SCV::init(int dir)
{
    Vertex vertices[] = {
        Vertex(glm::vec3(-0.5f,-0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f,-0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f, 0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f,-0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f, 0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f,-0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f,-0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f,-0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f, 0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f,-0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f,-0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f,-0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f, 0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f,-0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f,-0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f,-0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f,-0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f,-0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f,-0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f, 0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f,-0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f,-0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f, 0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f, 0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f, 0.5f,-0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0,1,0)),
        Vertex(glm::vec3(0.5f,-0.5f, 0.5f), glm::vec3(0,1,0))};

    initGameObject(vertices, sizeof(vertices)/sizeof(vertices[0]), (char*)"./res/basicShader");
    /*
    0 - up
    1 - right
    2 - down
    3 - left
    */
    direction = dir;
    alive = true;
}

void SCV::update()
{
    while(alive)
	{
		//sf::Lock lock(mutex);
        //1. scv moves 500 units on the specified direction at 0.01f
		if (direction == 0)
		{
			if (currentCommand == Command::Gather)
			{
				if (getY() < 5.0f)
					addY(0.01f);
				else
					currentCommand = Command::Return;
			}

			else if (currentCommand == Command::Return)
			{
				if (getY() > 0.0f)
					addY(-0.01f);

				else
				{
					mutex.lock();
					m_base->addMinerals(10);
					cout << "Mineral Count: " << m_base->getMineralCount() << endl;
					mutex.unlock();
					currentCommand = Command::Gather;
				}
			}
		}

		else if (direction == 1)
		{
			if (currentCommand == Command::Gather)
			{
				if (getX() < 5.0f)
					addX(0.01f);
				else
					currentCommand = Command::Return;
			}

			else if (currentCommand == Command::Return)
			{
				if (getX() > 0.0f)
					addX(-0.01f);

				else
				{
					mutex.lock();
					m_base->addMinerals(10);
					cout << "Mineral Count: " << m_base->getMineralCount() << endl;
					mutex.unlock();
					currentCommand = Command::Gather;
				}
			}
		}

		else if (direction == 2)
		{
			if (currentCommand == Command::Gather)
			{
				if (getY() > -5.0f)
					addY(-0.01f);
				else
					currentCommand = Command::Return;
			}

			else if (currentCommand == Command::Return)
			{
				if (getY() < 0.0f)
					addY(0.01f);

				else
				{
					mutex.lock();
					m_base->addMinerals(10);
					cout << "Mineral Count: " << m_base->getMineralCount() << endl;
					mutex.unlock();
					currentCommand = Command::Gather;
				}
			}
		}

		else if (direction == 3)
		{
			if (currentCommand == Command::Gather)
			{
				if (getX() > -5.0f)
					addX(-0.01f);
				else
					currentCommand = Command::Return;
			}

			else if (currentCommand == Command::Return)
			{
				if (getX() < 0.0f)
					addX(0.01f);

				else
				{
					mutex.lock();
					m_base->addMinerals(10);
					cout << "Mineral Count: " << m_base->getMineralCount() << endl;
					mutex.unlock();
					currentCommand = Command::Gather;
				}
			}
		}
        //2. scv moves 100- units at the oppostie direction at 0.005f
        //3. scv aquired a lock and ads 10 minerals to the base

		// if arrives in base
		sf::sleep(sf::milliseconds(5));
        //    the system should prompt stating the number of total minerals after the deposit
		//cout << "Total number or minerals: " << m_base.getMineralCount() << endl;

        
    }
    
    std::cout <<"end thread" << std::endl;
}

void SCV::dispose()
{
    alive = false;
}

void SCV::assignBase(Base* base)
{
	m_base = base;
}


double SCV::getSide()
{
    return 1;
}
