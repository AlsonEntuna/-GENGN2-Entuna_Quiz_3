#include "ModelTransform.h"

ModelTransform::ModelTransform(const glm::vec3& pos,
        const glm::vec3& rot, const glm::vec3& scale)
{
    this->pos = pos;
    this->rot = rot;
    this->scale = scale;
}

ModelTransform::~ModelTransform()
{
}

glm::mat4 ModelTransform::getModel() const{
    glm::mat4 posMat = glm::translate(pos);
    glm::mat4 scaleMat = glm::scale(scale);

    //gimble lock issue - 
    glm::mat4 rotX = glm::rotate(rot.x, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotY = glm::rotate(rot.y, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotZ = glm::rotate(rot.z, glm::vec3(0.0, 0.0, 1.0));
    //order matters

    //glm::mat4 rotMat = rotZ * rotY * rotX;    
    glm::mat4 rotMat = rotX * rotY * rotZ;
    
    return posMat * rotMat * scaleMat;
    //return scaleMat * rotMat * posMat;
}
