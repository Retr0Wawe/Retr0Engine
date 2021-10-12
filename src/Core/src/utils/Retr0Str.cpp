#include "utils/Retr0Str.hpp"

namespace Retr0Engine
{
	namespace Utils 
	{
		Retr0Str::Retr0Str(): str(new char()), length(1)
		{	}

		Retr0Str::Retr0Str(const char* _str) : length(strlen(_str) + 1)
		{
			str = new char[length]();
			str[length - 1] = '\0';
			strcpy(str, _str);
		}

		Retr0Str::Retr0Str(const Retr0Str& a)
		{
			length = a.get_length();
			str = new char[length]();

			str[length - 1] = '\0';
			strcpy(str, a.get_c_str());
		}

		Retr0Str::~Retr0Str()
		{
			if (str != nullptr) {
				delete[] str;
				str = nullptr;
			}
		}

		Retr0Str& Retr0Str::operator=(const Retr0Str& a)
		{
			if (this != &a) {
				delete[] str;
				length = a.get_length();

				str = new char[length]();
				str[a.get_length() - 1] = '\0';
				strcpy(str, a.get_c_str());
			}

			return *this;
		}

		bool Retr0Str::operator==(const Retr0Str& a)
		{
			return (this->length == a.length) && (strcmp(this->str, a.str)) == 0;
		}

		Retr0Str& Retr0Str::operator+=(const Retr0Str& a)
		{
			length = length + a.length;
			char* temp = new char[length];
			temp[length - 1] = '\0';

			strcpy(temp, str);
			strcat(temp, a.str);

			delete[] str;
			str = temp;
			
			return *this;
		}

		//Retr0Str& operator+(const Retr0Str& a, const Retr0Str& b);

		int Retr0Str::operator[](int i) const
		{
			return str[i];
		}

		int Retr0Str::get_length() const
		{
			return length;
		}

		char* Retr0Str::get_data() const
		{
			return str;
		}

		const char* Retr0Str::get_c_str() const
		{
			return static_cast<const char*>(str);
		}
	}
}