#ifndef WIN_HPP
#define WIN_HPP

#include <chrono>

#include "ImGuiLayer.hpp"

namespace Retr0Engine
{
	inline int result_code = -1;

	class Window : ImGuiLayer
	{
	private:
		unsigned int w_width, w_heigth;
		const char* w_title;
		GLFWwindow* w_pWindow;
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
		unsigned int get_width() const noexcept
		{ 
			return w_width; 
		}

		unsigned int get_heigth() const noexcept
		{ 
			return w_heigth; 
		}

		void callbacks_init() const noexcept;

		void on_update();

		virtual void gui_update() override;
	};
}

#endif