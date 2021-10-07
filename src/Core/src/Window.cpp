#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

#include "Window.hpp"
#include "Log.hpp"
#include "Callback.hpp"

namespace Retr0Engine
{
    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };

    const char* vertex_shader_source = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    const char* fragment_shader_source = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n\0";

    Window::Window(const char* _title, const unsigned int _width, const unsigned int _heigth) :
    w_title(_title), w_width(_width), w_heigth(_heigth), w_pWindow(nullptr)
	{
        result_code = init();
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
            
        ImGui::Begin("Retr0Gui");        //init imgui window

        ImGui::ColorEdit4("Background color", w_background);     //imgui widget

        ImGui::End();

        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        /// 
        unsigned int vbo;
        unsigned int vertex_shader;

        glGenBuffers(1, &vbo);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        
        glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);

        int succes;
        char infolog[512];

        glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &succes);

        if (succes != 0) {
            glGetShaderInfoLog(vertex_shader, 512, NULL, infolog);
            LOG_CRITICAL("Shader compile error! Error: {0}", infolog);
        }

        unsigned int fragment_shader;

        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        
        glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
        
        glCompileShader(fragment_shader);

        unsigned int shaderProgram;

        shaderProgram = glCreateProgram();

        glAttachShader(shaderProgram, vertex_shader);
        glAttachShader(shaderProgram, fragment_shader);
        glLinkProgram(shaderProgram);

        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &succes);

        if (succes != 0) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
            LOG_CRITICAL("Shader link error! Error: {0}", infolog);
        }

        glUseProgram(shaderProgram);

        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glUseProgram(shaderProgram);

        unsigned int vao;

        glGenVertexArrays(1, &vao);

        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

        glEnableVertexAttribArray(0);

        glUseProgram(shaderProgram);

        glBindVertexArray(vao);

        glUseProgram(shaderProgram);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 12);

        glfwSwapBuffers(w_pWindow);
        glfwPollEvents();
	}
}