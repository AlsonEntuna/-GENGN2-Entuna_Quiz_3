#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#define GLM_FORCE_RADIANS
#include <glm/gtx/transform.hpp>

class Camera
{
public:
	Camera(const glm::vec3& pos,float fov, float aspect, float znear, float zfar);
    glm::mat4 GetViewProjection() const;
protected:
private:
    glm::mat4 m_prespective;
    glm::vec3 m_position;
    glm::vec3 m_forward;
    glm::vec3 m_up;
};

#endif
