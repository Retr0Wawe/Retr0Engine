#ifndef APP_H	 //большенство компиляторов поддерживают именно данный header quard, потому что не требует дополнительных директив по типу #pragma once
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
		Application(); /*конструктор нужно определять в cpp файле вместе с инклудами для того чтобы 
						иметь доступ к функциоаналу импортируемых библиотек*/
		virtual ~Application();

		Application(const Application&) = delete;
		Application(Application&&) = delete;

		Application& operator=(const Application&) = delete;
		Application& operator=(const Application&&) = delete;

		virtual int start(const char* title, unsigned int w_weidth, unsigned int w_heigth);

		virtual void on_update();
	};
}

#endif