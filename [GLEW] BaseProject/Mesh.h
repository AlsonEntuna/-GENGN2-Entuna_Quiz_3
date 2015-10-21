#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
//added start
#include <GL/glew.h>
//added end
#include <vector>
#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
    public:
        Vertex(){}
        Vertex(const glm::vec3 posVal,const glm::vec3 colorVal)
		{
            setValue(posVal,colorVal);
        }
        void setValue(const glm::vec3 posVal,const glm::vec3 colorVal)
		{
            pos = posVal;
            color = colorVal;
        }
    //private:
        glm::vec3 pos;
        glm::vec3 color;
};

class Mesh{

public:    
    Mesh(Vertex* vertices,unsigned int numVertices);
    Mesh();
    void init(Vertex* vertices,unsigned int numVertices);
    ~Mesh();
    void draw();
private:
    //static const unsigned int NUM_BUFFERS = 4;
    enum{POSITION_VB,COLOR_VB,NUM_BUFFERS};

    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int n_drawCount;
};

#endif
