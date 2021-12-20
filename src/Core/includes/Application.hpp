#ifndef APP_H	 
#define APP_H	 

#include <memory>

namespace Retr0Engine
{
	inline bool a_Close_window = false;

	class Application
	{
	private:
		std::unique_ptr<class Window> pWindow;
	public:
		Application();		

		virtual ~Application();

		Application(const Application&) = delete;
		Application(Application&&) = delete;

		Application& operator=(const Application&) = delete;
		Application& operator=(const Application&&) = delete;
	public:
		int start(const char* title, std::size_t w_weidth, std::size_t w_heigth);

		virtual void on_update();
	};
}

#endif