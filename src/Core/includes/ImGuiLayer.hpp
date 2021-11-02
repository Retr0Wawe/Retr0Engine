#ifndef IMGUI_LAYER_H
#define IMGUI_LAYER_H

#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

namespace Retr0Engine
{
	class ImGuiLayer
	{
	protected:
		int error_code;
	public:
		ImGuiLayer();

		virtual ~ImGuiLayer();

		ImGuiLayer(const ImGuiLayer&) = delete;
		ImGuiLayer(ImGuiLayer&&) = delete;

		ImGuiLayer& operator=(const ImGuiLayer&) = delete;
		ImGuiLayer& operator=(const ImGuiLayer&&) = delete;
	public:
		int gui_init(GLFWwindow* p_window);

		virtual void gui_destroy() const;

		virtual void gui_update();

		virtual void pre_render() const;

		virtual void post_render() const;
	};
}

#endif