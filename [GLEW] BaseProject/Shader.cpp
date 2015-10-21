//https://github.com/BennyQBD/ModernOpenGLTutorial/blob/master/shader.cpp
#include "Shader.h"

Shader::Shader(const std::string& fileName){
	init(fileName);
}//end func

Shader::Shader(){
}//end func

void Shader::init(const std::string& fileName){
	m_program = glCreateProgram();
	m_shaders[0] = CreateShader(LoadShader(fileName + ".vs"), GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

	for(unsigned int i = 0; i < NUM_SHADERS; i++)
		glAttachShader(m_program, m_shaders[i]);

    //this maps the variavles in the vertex shader to the
    //data in functions out
	glBindAttribLocation(m_program, 0, "position");
	glBindAttribLocation(m_program, 1, "color");

	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "Error linking shader program");

	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "Invalid shader program");
 
	m_uniforms[TRANSFORM_U] = glGetUniformLocation(m_program, "transform");
}//end func

Shader::~Shader(){
	for(unsigned int i = 0; i < NUM_SHADERS; i++){
        glDetachShader(m_program, m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }//end for

	glDeleteProgram(m_program);
}//end func

void Shader::bind(){
	glUseProgram(m_program);
}//end func


void Shader::update(ModelTransform& transform){
    glm::mat4 transModel = transform.getModel();
    glUniformMatrix4fv(m_uniforms[TRANSFORM_U],//what uniform we want to send
        1,// number of params
        GL_FALSE,//do you want to transpose
        &transModel[0][0]);//send the address of the starting address
    
}

void Shader::update(ModelTransform& transform, const Camera& cam){
    glm::mat4 transModel = cam.GetViewProjection() * transform.getModel();
    glUniformMatrix4fv(m_uniforms[TRANSFORM_U],//what uniform we want to send
        1,// number of params
        GL_FALSE,//do you want to transpose
        &transModel[0][0]);//send the address of the starting address
    
}


//==== ==== ==== ==== ==== ==== ====
// HELPER FUNCTIONS
//==== ==== ==== ==== ==== ==== ====

/**
* loads file into memory
*/
std::string Shader::LoadShader(const std::string& fileName){
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if(file.is_open()){
        while(file.good()){
            getline(file, line);
			output.append(line + "\n");
        }//end while
    }else{
		std::cerr << "Unable to load shader: " << fileName << std::endl;
    }//end else

    return output;
}//end func

/**
* Checks the error
*/
void Shader::CheckShaderError(GLuint shader, GLuint flag,
        bool isProgram, const std::string& errorMessage){
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE){
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }//end if
}//end func

/**
* Creates the shader program used
*/
GLuint Shader::CreateShader(const std::string& text, GLenum type){
    GLuint shader = glCreateShader(type);

    if(shader == 0)
		std::cerr << "Error compiling shader type " << type << std::endl;

    const GLchar* shaderSourceString[1];
    shaderSourceString[0] = text.c_str();

    GLint shaderSourceLength[1];
    shaderSourceLength[0] = text.length();

    glShaderSource(shader,//the acutal shader
        1,//the number of sources
        shaderSourceString,//string cont
        shaderSourceLength);//string len
    glCompileShader(shader);

    CheckShaderError(shader, GL_COMPILE_STATUS, false,//its just a shader only
        "Error compiling shader!");

    return shader;
}//end func
