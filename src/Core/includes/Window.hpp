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
		std::size_t w_width, w_heigth;
		const char* w_title;
		GLFWwindow* w_pWindow;
		float w_background[4] = { 0.f, 0.f, 0.f };
	private:
		int init();
		void shutdown() const;
	public:
		Window(const char* _title, const uint32_t _width, const uint32_t _heigth);

		~Window();

		Window(const Window&) = delete;
		Window(Window&&) = delete;

		Window& operator=(const Window&) = delete;
		Window& operator=(const Window&&) = delete;
	public:
		uint32_t get_width() const noexcept
		{ return w_width; }

		uint32_t get_heigth() const noexcept 
		{ return w_heigth; }

		void callbacks_init() const noexcept;

		virtual void gui_update() override;

		void on_update();
	};
}

#endif