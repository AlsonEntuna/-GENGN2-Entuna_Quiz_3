#ifndef SHADER_H
#define SHADER_H

//added start
#include <string>
//added end
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "ModelTransform.h"
#include "Camera.h"

class Shader{
public:
	Shader(const std::string& fileName);
	Shader();
	void init(const std::string& fileName);
    virtual ~Shader();

	void bind();
    void update(ModelTransform& transform);
	void update(ModelTransform& transform, const Camera& cam);
protected:
private:
	static const unsigned int NUM_SHADERS = 2;
	//static const unsigned int NUM_UNIFORMS = 3;
    enum{TRANSFORM_U,NUM_UNIFORMS};

	std::string LoadShader(const std::string& fileName);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	GLuint CreateShader(const std::string& text, GLenum type);

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];
};

#endif
