#ifndef GAMEOBJECT_H
#define	GAMEOBJECT_H

#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"
#include "ModelTransform.h"

class GameObject 
{
    public:
        GameObject();
        GameObject(Vertex* vertices,unsigned int numVertices,char* shaderFile);
        void initGameObject(Vertex* vertices,unsigned int numVertices,char* shaderFile);
        virtual void update() = 0;
        void draw(const Camera& camera);
        ModelTransform* getTransform();
        
        void setX(double x);
        double getX();
        void setY(double y);
        double getY();
        void setZ(double z);
        double getZ();
		void addX(double x);
		void addY(double y);
    private:
        Mesh mesh;
        Shader shader;
        ModelTransform transform;
};

#endif	/* GAMEOBJECT_H */
