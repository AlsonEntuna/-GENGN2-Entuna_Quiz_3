#ifndef SCV_H
#define	SCV_H

#include <SFML/System.hpp>
#include "GameObject.h"
#include "Camera.h"
#include "Base.h"
#include <iostream>

using namespace std;

class SCV : public GameObject
{
    public:
		enum Command
		{
			Gather,
			Return
		};
		Command currentCommand;
        SCV();
        SCV(int dir);
        void init(int dir);
        void update();
        double getSide();
        void dispose();
        static sf::Mutex mutex;

		void assignBase(Base* base);
    private:
        int direction;
        bool alive;
		Base* m_base; // reference to the base
};

#endif	/* SCV_H */

