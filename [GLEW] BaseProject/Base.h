#ifndef BASE_H
#define	BASE_H

#include <SFML/System.hpp>
#include "GameObject.h"
#include "Camera.h"
#include <iostream>

using namespace std;

class Base : public GameObject
{
public:
    Base();
    void init();
    void update();
    double getSide();
    //4. variable for locking the scv deposits
	static sf::Mutex mutex;
    //5. variable for storing the mineral amount
	int& getMineralCount();
	void addMinerals(int value);
private:
	int m_mineralCount;
	
};

#endif	/* BASE_H */

