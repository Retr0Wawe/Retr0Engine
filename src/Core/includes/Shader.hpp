#ifndef SHADER_CPP
#define SHADER_CPP

#include <iostream>
#include "utils/Retr0Str.hpp"

namespace Retr0Engine
{
	class Shader
	{
	public:					//потом сделать private, так как создание шейдеров будет проходить внутри методов класса
		std::string vertex_code;
		std::string fragment_code;
	public:
		Shader() = delete;

		Shader(const Shader&) = delete;
		Shader(Shader&&) = delete;

		Shader& operator=(const Shader&) = delete;
		Shader& operator=(const Shader&&) = delete;

		Shader(const char* vertex_path, const char* fragment_path);

		~Shader();
	public:
		void get_shaders_code() const;
	};
}

#endif