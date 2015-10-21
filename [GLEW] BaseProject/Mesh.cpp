#include "Mesh.h"

Mesh::Mesh(Vertex* vertices,unsigned int numVertices){
    init(vertices,numVertices);
}

Mesh::Mesh(){
}


void Mesh::init(Vertex* vertices,unsigned int numVertices){
    n_drawCount = numVertices;

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    std::vector<glm::vec3> positions;
    std::vector<glm::vec3> colors;

    positions.reserve(numVertices);

    for(unsigned i = 0; i < numVertices; i++){
        positions.push_back(vertices[i].pos);
        colors.push_back(vertices[i].color);
    }

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);

    //vertex buffer data
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions[0]) * numVertices,
        &positions[0], GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    //color buffer data
     
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[COLOR_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors[0]) * numVertices,
        &colors[0], GL_STATIC_DRAW);


    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);
}


Mesh::~Mesh(){
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::draw(){
    glBindVertexArray(m_vertexArrayObject);
    glDrawArrays(GL_TRIANGLES,//what kind
        0,//start
        n_drawCount);//end
    glBindVertexArray(0);
}
