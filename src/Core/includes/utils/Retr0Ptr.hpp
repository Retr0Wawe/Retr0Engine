#ifndef R_PTR
#define R_PTR

namespace Retr0Engine
{
	template <class T>
	class Retr0Ptr
	{
	protected:
		T* ptr;
	public:
		Retr0Ptr(T _ptr);

		~Retr0Ptr();

		T& operator->() const;

		T& operator*() const;
	};
}

#endif