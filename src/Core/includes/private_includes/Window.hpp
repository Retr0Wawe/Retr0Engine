#ifndef WIN_HPP
#define WIN_HPP

namespace Retr0Engine
{
	class Window
	{
	private:
		unsigned int w_width;
		unsigned int w_heigth;
		const char* w_title;
		struct GLFWwindow* w_pWindow;
	private:
		int init();
		void shutdown() const;
	public:
		Window(const char* _title, const unsigned int _width, const unsigned int _heigth);

		~Window();

		Window(const Window&) = delete;
		Window(Window&&) = delete;

		Window& operator=(const Window&) = delete;
		Window& operator=(const Window&&) = delete;

		unsigned int get_width() const { return w_width; }

		unsigned int get_heigth() const { return w_heigth; }

		virtual void on_update() const;
	};
}

#endif