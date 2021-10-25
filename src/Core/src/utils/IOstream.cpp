#include "utils/IOstream.hpp"

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
			//std::cout << "Error to open file! " << err.what() << std::endl;
		}
	}
}