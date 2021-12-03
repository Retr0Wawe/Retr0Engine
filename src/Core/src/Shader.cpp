#include <fstream>
#include <sstream>
#include <iostream>

#include "Shader.hpp"
#include "Log.hpp"

namespace Retr0Engine
{
	Shader::Shader(const char* vertex_path, const char* fragment_path): error_code(0)
	{	
		std::ifstream vertex_file, fragment_file;

		vertex_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fragment_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try {
			std::stringstream vertex_buf, fragment_buf;

			vertex_file.open(vertex_path);
			fragment_file.open(fragment_path);

			vertex_buf << vertex_file.rdbuf();
			fragment_buf << fragment_file.rdbuf();

			vertex_code = vertex_buf.str();
			fragment_code = fragment_buf.str();
		}
		catch (const std::fstream::failure& err) {
			LOG_CRITICAL("Error to read files! ({0})", err.what()); 
			error_code = -1;
		}
	}

	Shader::~Shader()
	{
		glDeleteProgram(shader_id); 
	}

	void Shader::bind() const
	{
		glUseProgram(shader_id);
	}

	void Shader::unbind() 
	{
		glUseProgram(0);
	}

	int Shader::init_shader_program()
	{
		GLuint vertex_id, fragment_id;
		GLint succes;

		if (!create_shader(vertex_code.c_str(), GL_VERTEX_SHADER, vertex_id)) {
			LOG_CRITICAL("Vertex shader compile error!");
			glDeleteShader(vertex_id);
			error_code = -2;
			return error_code;
		}

		if (!create_shader(fragment_code.c_str(), GL_FRAGMENT_SHADER, fragment_id)) {
			LOG_CRITICAL("Fragment shader compile error!");
			glDeleteShader(vertex_id);
			glDeleteShader(fragment_id);

			error_code = -3;
			return error_code;
		}

		shader_id = glCreateProgram();

		glAttachShader(shader_id, vertex_id);
		glAttachShader(shader_id, fragment_id);

		glLinkProgram(shader_id);

		glGetProgramiv(shader_id, GL_LINK_STATUS, &succes);

		if (succes == GL_FALSE) {
			char log[1024];
			glGetProgramInfoLog(shader_id, 1024, nullptr, log);

			LOG_CRITICAL("Error to link shader program! Error: \n{0}", log);
			glDeleteProgram(shader_id);

			shader_id = 0;

			glDeleteShader(vertex_id);
			glDeleteShader(fragment_id);

			error_code = -4;
			return error_code;
		}

		glDetachShader(shader_id, vertex_id);
		glDetachShader(shader_id, fragment_id);

		glDeleteShader(vertex_id);
		glDeleteShader(fragment_id);

		return 0;
	}

	bool Shader::create_shader(const char* source, const GLenum shader_type, GLuint& shader_id)
	{
		GLint succes;
		
		shader_id = glCreateShader(shader_type);
		
		glShaderSource(shader_id, 1, &source, nullptr);
		glCompileShader(shader_id);

		glGetShaderiv(shader_id, GL_COMPILE_STATUS, &succes);

		if (succes == GL_FALSE) {
			char log[1024];

			glGetShaderInfoLog(shader_id, 1024, nullptr, log);
			LOG_CRITICAL("Error to compile shader! Error: \n{0}", log);
			
			return false;
		} 
		return true;
	}
}