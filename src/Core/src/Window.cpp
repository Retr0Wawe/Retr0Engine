#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include <imgui/backends/imgui_impl_glfw.h>

#include "Window.hpp"
#include "Log.hpp"
#include "Callback.hpp"

namespace Retr0Engine
{
    Window::Window(const char* _title, const unsigned int _width, const unsigned int _heigth) :
    w_title(_title), w_width(_width), w_heigth(_heigth), w_pWindow(nullptr)
	{
        int result_code = init();

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui_ImplOpenGL3_Init();
        ImGui_ImplGlfw_InitForOpenGL(w_pWindow, true);
	}

	Window::~Window()
	{
        glfwDestroyWindow(w_pWindow);
        glfwTerminate();
	}

	int Window::init()
	{
        LOG_INFO("Initalize window with: [title->{0}]; [window resolution->{1}*{2}]", w_title, w_width, w_heigth);    
 
        if (!glfwInit()) {
            LOG_CRITICAL("Error to glfw initialize!");
            return -1;
        }
        
        w_pWindow = glfwCreateWindow(w_width, w_heigth, w_title, NULL, NULL);

        if (!w_pWindow) {
            LOG_CRITICAL("Can't create window! {0} {1}*{2}", w_title, w_width, w_heigth);
            glfwTerminate();
            return -2;
        }

        glfwMakeContextCurrent(w_pWindow);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            LOG_CRITICAL("Error init glad!");
            return -3;
        }

        callbacks_init();

        return 0;
	}

    void Window::callbacks_init() const
    {
        glfwSetKeyCallback(w_pWindow, key_callback);                    //key callback
        glfwSetMouseButtonCallback(w_pWindow, mouse_button_callback);   //mouse button callback 
        glfwSetCursorPosCallback(w_pWindow, cursor_position_callback);  //cursor position callback
        glfwSetWindowCloseCallback(w_pWindow, window_close_callback);   //window close callback
        glfwSetWindowSizeCallback(w_pWindow, window_size_callback);     //window size callback
    }

	void Window::shutdown() const
	{
        glfwDestroyWindow(w_pWindow);
        glfwTerminate();
	}

	void Window::on_update() 
	{
        glClearColor(w_background[0], w_background[1], w_background[2], w_background[3]);      //specifies the values ​​for clearing the color of the color buffer.
        glClear(GL_COLOR_BUFFER_BIT);       //clearing the color buffer so that when drawing colors do not overlap each other
            
        ImGuiIO& io = ImGui::GetIO();       //get context

        io.DisplaySize.x = (float)get_width();
        io.DisplaySize.y = (float)get_heigth();
        
        ImGui_ImplOpenGL3_NewFrame();       //create imgui objects with opengl, shader compile, bind vertex and more

        ImGui_ImplGlfw_NewFrame();          //handling Imgui clicks with glfw to interact with the window or widgets

        ImGui::NewFrame();                 

        ImGui::Begin("Retr0Gui");   //init imgui window

        ImGui::ColorEdit4("Background color", w_background);    //imgui widget

        ImGui::End();

        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(w_pWindow);
        glfwPollEvents();
	}
}