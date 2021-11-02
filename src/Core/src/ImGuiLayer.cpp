#include "ImGuiLayer.hpp"

namespace Retr0Engine
{
	ImGuiLayer::ImGuiLayer(): error_code(0)
	{
		IMGUI_CHECKVERSION();
	}

	int ImGuiLayer::gui_init(GLFWwindow* p_window)
	{
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO();

		if (!ImGui_ImplOpenGL3_Init("#version 300 es")) {
			error_code = -1;
			return error_code;
		}

		if (!ImGui_ImplGlfw_InitForOpenGL(p_window, true)) {
			error_code = -2;
			return error_code;
		}
	
		return error_code;
	}

	void ImGuiLayer::gui_destroy() const
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	ImGuiLayer::~ImGuiLayer()
	{
		gui_destroy();
	}

	void ImGuiLayer::pre_render() const
	{
		ImGui_ImplOpenGL3_NewFrame();       //create imgui objects with opengl, shader compile, bind vertex and more
		ImGui_ImplGlfw_NewFrame();          //handling Imgui clicks with glfw to interact with the window or widgets
		ImGui::NewFrame();
	}

	void ImGuiLayer::gui_update()
	{
		pre_render();

		ImGui::Begin("Retr0Engine");
		ImGui::Text("Base method");

		post_render();
	}

	void ImGuiLayer::post_render() const
	{
		ImGui::End();
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}