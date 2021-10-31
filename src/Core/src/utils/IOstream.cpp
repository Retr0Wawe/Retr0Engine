#include <sstream>
#include <filesystem>

#include "utils/IOstream.hpp"
#include "Log.hpp"

namespace Retr0Engine
{
	IOfile::IOfile()
	{
		file.exceptions(std::fstream::failbit | std::fstream::badbit);
		file_path = std::filesystem::current_path().generic_string();
	}

	IOfile::IOfile(const char* path_to_file): file_path(path_to_file)
	{
		file.exceptions(std::fstream::failbit | std::fstream::badbit);

		try {
			file.open(file_path);
		}
		catch (const std::fstream::failure& err) {
			LOG_CRITICAL("Error to open file [{0}]! Error: {1}", file_path, err.what());
		}
	}

	IOfile::~IOfile()
	{	}

	std::string IOfile::read_data() 
	{
		
	}

	bool IOfile::write_data(const char* str) const
	{
		return true;
	}
	
	std::string IOfile::get_file_path() const
	{
		return file_path;
	}

	void IOfile::close()
	{
		try {
			file.close();
		}
		catch (const std::fstream::failure& err) {
			LOG_CRITICAL("Error to close file! Error: {0}", err.what());
		}
	}

	IOfile& IOfile::operator=(const char* path) 
	{
		file_path = path;

		file.open(file_path);

		return *this;
	}
}