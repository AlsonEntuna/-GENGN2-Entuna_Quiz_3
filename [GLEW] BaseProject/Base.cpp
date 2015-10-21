#include "Base.h"

#define X .525731112119133606 
#define Z .850650808352039932

Base::Base()
{
	init();
}

void Base::init()
{
	m_mineralCount = 0; // default 
    //http://www.glprogramming.com/red/chapter02.html#name8
    static GLfloat vdata[12][3] = {    
       {-X, 0.0, Z}, {X, 0.0, Z}, {-X, 0.0, -Z}, {X, 0.0, -Z},    
       {0.0, Z, X}, {0.0, Z, -X}, {0.0, -Z, X}, {0.0, -Z, -X},    
       {Z, X, 0.0}, {-Z, X, 0.0}, {Z, -X, 0.0}, {-Z, -X, 0.0} };
    static GLuint tindices[20][3] = { 
       {0,4,1}, {0,9,4}, {9,5,4}, {4,5,8}, {4,8,1},    
       {8,10,1}, {8,3,10}, {5,3,8}, {5,2,3}, {2,7,3},    
       {7,10,3}, {7,6,10}, {7,11,6}, {11,0,6}, {0,1,6}, 
       {6,1,10}, {9,0,11}, {9,11,2}, {9,2,5}, {7,2,11} };

    Vertex vertices[60];    

    for (int i = 0; i < 20; i++) {
        vertices[i*3].setValue(glm::vec3(
            vdata[tindices[i][0]][0],
            vdata[tindices[i][0]][1],
            vdata[tindices[i][0]][2]), glm::vec3(1,0,0));
        vertices[i*3+1].setValue(glm::vec3(
            vdata[tindices[i][1]][0],
            vdata[tindices[i][1]][1],
            vdata[tindices[i][1]][2]), glm::vec3(1,0,0));
        vertices[i*3+2].setValue(glm::vec3(
            vdata[tindices[i][2]][0],
            vdata[tindices[i][2]][1],
            vdata[tindices[i][2]][2]), glm::vec3(1,0,0));
    }//end for

    initGameObject(vertices, sizeof(vertices)/sizeof(vertices[0]), (char*)"./res/basicShader");
}

void Base::update()
{
}

double Base::getSide()
{
	return 1;
}

int& Base::getMineralCount()
{
	return m_mineralCount;
}

void Base::addMinerals(int value)
{
	//cout << "Adding: " << value << " minerals" << endl;
	m_mineralCount += value;
	//cout << "Current: " << m_mineralCount << " minerals" << endl;
}

