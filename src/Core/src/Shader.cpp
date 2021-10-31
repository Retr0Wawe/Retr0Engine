#include "Shader.hpp"
#include "Log.hpp"

#include <fstream>
#include <sstream>
#include <filesystem>

namespace Retr0Engine
{
	Shader::Shader(const char* vertex_path, const char* fragment_path)
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
		}

		LOG_INFO("Shaders are read successfully!");
	}

	Shader::~Shader()
	{	}

	void Shader::get_shaders_code() const
	{
		std::cout << vertex_code << std::endl;
		std::cout << fragment_code << std::endl;
	}
}