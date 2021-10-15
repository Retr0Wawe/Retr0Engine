#ifndef WIN_HPP
#define WIN_HPP

namespace Retr0Engine
{
	inline int result_code = -1;

	class Window
	{
	private:
		unsigned int w_width, w_heigth;
		const char* w_title;
		struct GLFWwindow* w_pWindow;
		float w_background[4] = { 0.f, 0.f, 0.f };
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
	public:
		unsigned int get_width() const { return w_width; }

		unsigned int get_heigth() const { return w_heigth; }

		void callbacks_init() const;

		void on_update();
	};
}

#endif