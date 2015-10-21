#ifndef MODEL_TRANSFORM_H
#define MODEL_TRANSFORM_H

#include <glm/glm.hpp>
#define GLM_FORCE_RADIANS
#include <glm/gtx/transform.hpp>

class ModelTransform
{
public:
	ModelTransform(const glm::vec3& pos = glm::vec3(),
        const glm::vec3& rot = glm::vec3(),
        const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f));
	virtual ~ModelTransform();

    inline glm::vec3* GetPos(){ return &pos; }
	inline glm::vec3* GetRot() { return &rot; }
	inline glm::vec3* GetScale() { return &scale; }

	inline void SetPos(glm::vec3& pos) { this->pos = pos; }
	inline void SetRot(glm::vec3& rot) { this->rot = rot; }
	inline void SetScale(glm::vec3& scale) { this->scale = scale; }

    glm::mat4 getModel() const;
protected:
private:
    glm::vec3 pos;
    glm::vec3 rot;
    glm::vec3 scale;
};

#endif
