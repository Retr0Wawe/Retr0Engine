#ifndef IOSTREAM_HPP
#define IOSTREAM_HPP

#include <fstream>

namespace Retr0Engine
{
	class IOfile
	{
	protected:
		std::fstream file;
		std::string file_path;
		char* buffer;
	public:
		IOfile();

		IOfile(const char* path_to_file);

		virtual ~IOfile();

		IOfile(const IOfile&) = delete;
		IOfile(IOfile&&) = delete;

		IOfile& operator=(const IOfile&) = delete;
		IOfile& operator=(const IOfile&&) = delete;
	public:
		virtual std::string read_data();

		virtual bool write_data(const char* str) const;

		std::string get_file_path() const;

		void close();

		IOfile& operator=(const char* str);
	};
}

#endif