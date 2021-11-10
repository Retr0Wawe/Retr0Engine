#ifndef SHADER_CPP
#define SHADER_CPP

#include <iostream>
#include <glad/glad.h>

namespace Retr0Engine
{
	class Shader
	{
	private:					
		std::string vertex_code;
		std::string fragment_code;
	public:
		unsigned int shader_id;
		int error_code;
	public:
		Shader(const char* vertex_path, const char* fragment_path);

		~Shader();

		Shader() = delete;

		Shader(const Shader&) = delete;
		Shader(Shader&&) = delete;

		Shader& operator=(const Shader&) = delete;
		Shader& operator=(const Shader&&) = delete;
	public:
		bool create_shader(const char* source, const GLenum shader_type, GLuint& shader_id);

		int init_shader_program();

		void bind() const;

		void unbind() const;
	};
}

#endif