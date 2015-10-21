#include "GameObject.h"

GameObject::GameObject(){}

GameObject::GameObject(Vertex* vertices,unsigned int numVertices,char* shaderFile){
    initGameObject(vertices,numVertices,shaderFile);
}

void GameObject::initGameObject(Vertex* vertices,unsigned int numVertices,char* shaderFile){
    mesh.init(vertices,numVertices);
    shader.init(shaderFile);
}

void GameObject::draw(const Camera& camera){
    shader.bind();
    shader.update(transform,camera);
    mesh.draw();
}

ModelTransform* GameObject::getTransform(){
    return &transform;
}

void GameObject::setX(double x){
    transform.GetPos()->x = x;
}

double GameObject::getX(){
    return transform.GetPos()->x;
}

void GameObject::setY(double y){
    transform.GetPos()->y = y;
}

double GameObject::getY(){
    return transform.GetPos()->y;
}

void GameObject::setZ(double z){
    transform.GetPos()->z = z;
}

double GameObject::getZ(){
    return transform.GetPos()->z;
}

void GameObject::addX(double x)
{
	transform.GetPos()->x += x;
}

void GameObject::addY(double y)
{
	transform.GetPos()->y += y;
}
