#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Window.hpp"
#include "Log.hpp"
#include "Callback.hpp"

namespace Retr0Engine
{
    static bool GLFW_init = false;

    Window::Window(const char* _title, const unsigned int _width, const unsigned int _heigth) :
    w_title(_title), w_width(_width), w_heigth(_heigth), w_pWindow(nullptr)
	{
        init();
	}

	Window::~Window()
	{
        glfwDestroyWindow(w_pWindow);
        glfwTerminate();
	}

	int Window::init()
	{
        LOG_INFO("Initalize window with: [title->{0}]; [window resolution->{1}*{2}]", w_title, w_width, w_heigth);    

        if (!GLFW_init) {
            if (!glfwInit()) {
                LOG_CRITICAL("Error to glfw initialize!");
                return -1;
            }
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

        glfwSetKeyCallback(w_pWindow, key_callback);
        glfwSetMouseButtonCallback(w_pWindow, mouse_button_callback);
        glfwSetCursorPosCallback(w_pWindow, cursor_position_callback);
        glfwSetWindowCloseCallback(w_pWindow, window_close_callback);
        glfwSetWindowSizeCallback(w_pWindow, window_size_callback);

        return 0;
	}

	void Window::shutdown() const
	{
        glfwDestroyWindow(w_pWindow);
        glfwTerminate();
	}

	void Window::on_update() const
	{
        glClearColor(1, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(w_pWindow);
        glfwPollEvents();
	}
}