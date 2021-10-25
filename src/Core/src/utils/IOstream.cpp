#include <sstream>

#include "utils/IOstream.hpp"
#include "Log.hpp"

namespace Retr0Engine
{
	IOstream::IOstream()
	{	}

	IOstream::IOstream(const char* path)
	{
		file.exceptions(std::fstream::failbit | std::fstream::badbit);

		try {
			file.open(path);
		}
		catch (const std::fstream::failure& err) {
			LOG_CRITICAL("Error to open file! Error: {0}", err.what());
		}
	}

	IOstream::~IOstream()
	{	}

	std::string IOstream::read_data() const
	{
		std::stringstream stream;

		try {
			stream << file.rdbuf();

			return stream.str();
		}
		catch (const std::fstream::failure& err) {
			LOG_CRITICAL("Error to read file! Error: {0}", err.what());
		}
		return "";
	}

	bool IOstream::write_data(const char* str) 
	{
		return true;
	}
}