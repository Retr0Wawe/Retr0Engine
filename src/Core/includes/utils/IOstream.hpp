#ifndef IOSTREAM_HPP
#define IOSTREAM_HPP

#include <fstream>

namespace Retr0Engine
{
	class IOstream
	{
	protected:
		std::fstream file;
	public:
		IOstream()
		{	}

		IOstream(const char* path);

		~IOstream()
		{	}

		virtual std::string read_data() const;

		bool write_data(const char* str);
	};

}


#endif