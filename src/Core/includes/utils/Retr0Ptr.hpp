#ifndef R_PTR
#define R_PTR

namespace Retr0Engine
{
	template <class T>
	class Retr0Unique_Ptr
	{
	private:
		T* ptr;
	public:
		Retr0Unique_Ptr(T* _ptr = nullptr) : ptr(_ptr)
		{	}

		~Retr0Unique_Ptr()
		{
			delete ptr;
		}

		T& operator->() const
		{
			return ptr;
		}

		T& operator*() const
		{
			return *ptr;
		}
	};
}

#endif