#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Window.hpp"
#include "Log.hpp"
#include "Callback.hpp"
#include "Shader.hpp"

namespace Retr0Engine
{
    float points[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };

    float colors[] = {
     0.5f, 0.0f, 0.0f,
     0.0f, 0.0f, 0.0f,
     0.0f, 0.0f, 1.0f
    };

    GLuint vao;
    std::unique_ptr<Shader> shader;

    Window::Window(const char* _title, const unsigned int _width, const unsigned int _heigth) :
        w_title(_title), w_width(_width), w_heigth(_heigth), w_pWindow(nullptr)
	{
        result_code = init();
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

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        w_pWindow = glfwCreateWindow(w_width, w_heigth, w_title, NULL, NULL);

        if (!w_pWindow) {
            LOG_CRITICAL("Can't create window! {0} {1}*{2}", w_title, w_width, w_heigth);
            glfwTerminate();
            return -2;
        }

        glfwMakeContextCurrent(w_pWindow);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            LOG_CRITICAL("Error to init glad!");
            return -3;
        }

        callbacks_init();

        if (gui_init(w_pWindow)) {
            LOG_CRITICAL("Error to imgui init! Error: {0}", error_code);
            return -4;
        }

        shader = std::make_unique<Shader>("shaders/vertex.txt", "shaders/fragment.txt");

        if (!shader->is_compiled()) {
            LOG_CRITICAL("Error to compile shaders!");
            return -5;
        }

        GLuint points_vbo, colors_vbo;
        
        glGenBuffers(1, &points_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
        
        glGenBuffers(1, &colors_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

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

    void Window::gui_update()
    {
        pre_render();

        ImGui::Begin("Retr0Gui");   //init imgui window

        ImGui::ColorEdit4("Background color", w_background);    //imgui widget
        ImGui::ColorEdit3("Object color", colors);

        post_render();
    }

	void Window::on_update()
	{
        glClearColor(w_background[0], w_background[1], w_background[2], w_background[3]);      //specifies the values ​​for clearing the color of the color buffer.
        glClear(GL_COLOR_BUFFER_BIT);       //clearing the color buffer so that when drawing colors do not overlap each other
        
        shader->bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        gui_update();                       //gui update function
                                            //render objects
        glfwSwapBuffers(w_pWindow);
        glfwPollEvents();
	}
}