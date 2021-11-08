#ifndef SHADER_CPP
#define SHADER_CPP

#include <iostream>
#include <glad/glad.h>

namespace Retr0Engine
{
	class Shader
	{
	private:						//потом сделать private, так как создание шейдеров будет проходить внутри методов класса
		std::string vertex_code;
		std::string fragment_code;
		unsigned int shader_id;
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

		bool is_compiled() const;

		void bind() const;

		void unbind() const;
	};
}

#endif