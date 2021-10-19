#include "utils/Retr0Str.hpp"

#include <string.h>

namespace Retr0Engine
{
	Retr0Str::Retr0Str(): str(new char[0]()), length(0) //����������� �������� null���������� - a = new char[1]; a[1] = '\0';
	{	}

	Retr0Str::Retr0Str(const char* _str)
	{
		if (_str != nullptr) {
			length = strlen(_str) + 1;
			str = new char[length]();
			str[length - 1] = '\0';
			strcpy(str, _str);
		}
		else {
			length = 0;
			str = new char[0]();
		}
	}

	Retr0Str::Retr0Str(const Retr0Str& a)
	{
		if (a.str != nullptr && a.length != 0) {
			length = a.length;
			str = new char[length]();
			str[length - 1] = '\0';
			strcpy(str, a.str);
		}
		else {
			length = 0;
			str = new char[0]();
		}
	}

	Retr0Str::~Retr0Str()
	{
		delete[] str;
		str = nullptr;
	}

	Retr0Str& Retr0Str::operator=(const Retr0Str& a)
	{
		if (this != &a) {
			delete[] str;
			length = a.length;

			str = new char[length]();
			str[length - 1] = '\0';
			strcpy(str, a.str);
		}

		return *this;
	}

	Retr0Str& Retr0Str::operator+=(const Retr0Str& a)
	{
		length = (length + a.length);
		char* temp = new char[length];
		temp[length - 1] = '\0';

		strcpy(temp, str);
		strcat(temp, a.str);

		delete[] str;
		str = temp;

		return *this;
	}

	Retr0Str operator+(Retr0Str& a, const Retr0Str& b)
	{
		return Retr0Str(a) += b;
	}

	bool operator>(const Retr0Str & a, const Retr0Str& b) 
	{
		return a.length > b.length;
	}

	bool operator<(const Retr0Str& a, const Retr0Str& b)
	{
		return a.length < b.length;
	}

	bool operator>=(const Retr0Str& a, const Retr0Str& b)
	{
		return a.length >= b.length;
	}

	bool operator<=(const Retr0Str& a, const Retr0Str& b)
	{
		return a.length <= b.length;
	}

	bool operator!=(const Retr0Str& a, const Retr0Str& b)
	{
		return ((a.length != b.length) && strcmp(a.str, b.str) != 0);
	}

	bool operator==(const Retr0Str& a, const Retr0Str& b)
	{
		return (a.length == b.length) && (strcmp(a.str, b.str)) == 0;
	}

	char& Retr0Str::operator[](int i) const
	{
		return str[i];
	}

	int Retr0Str::len() const
	{
		return length;
	}

	char* Retr0Str::data() const
	{
		return str;
	}

	const char* Retr0Str::c_str() const
	{
		return static_cast<const char*>(str);
	}
}