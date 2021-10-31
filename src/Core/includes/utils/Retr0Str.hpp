#ifndef R_STR
#define R_STR

#include <ostream>

namespace Retr0Engine
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

		Retr0Str& operator+=(const Retr0Str&);

		friend Retr0Str operator+(Retr0Str&, const Retr0Str&);

		friend bool operator>(const Retr0Str&, const Retr0Str&);

		friend bool operator<(const Retr0Str&, const Retr0Str&);

		friend bool operator>=(const Retr0Str&, const Retr0Str&);

		friend bool operator<=(const Retr0Str&, const Retr0Str&);

		friend bool operator!=(const Retr0Str&, const Retr0Str&);

		friend bool operator==(const Retr0Str&, const Retr0Str&);

		friend std::ostream& operator<<(std::ostream& out, const Retr0Str&);

		friend std::istream& operator>>(std::istream& inp, const Retr0Str&);

		char& operator[](int i) const;

		int len() const;

		char* data() const;

		const char* c_str() const;
	};
}

#endif
