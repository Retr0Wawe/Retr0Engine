#ifndef R_STR
#define R_STR

#include <string.h>
#include <iostream>

namespace Retr0Engine
{
	namespace Utils
	{
		class Retr0Str
		{
		protected:
			char* str;
			int length;
		public:
			Retr0Str();

			Retr0Str(const char* _str);

			Retr0Str(const Retr0Str&);

			~Retr0Str();

			Retr0Str& operator=(const Retr0Str&);

			bool operator==(const Retr0Str&);

			Retr0Str& operator+=(const Retr0Str&);

			friend Retr0Str& operator+(const Retr0Str&, const Retr0Str&);

			int operator[](int i) const;

			int get_length() const;

			char* get_data() const;	

			const char* get_c_str() const;
		};
	}
}

#endif
