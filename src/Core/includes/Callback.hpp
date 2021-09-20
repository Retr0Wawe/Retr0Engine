#ifndef CALL_HPP
#define CALL_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Application.hpp"
#include "Log.hpp"

namespace Retr0Engine
{
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

    void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

    void window_size_callback(GLFWwindow* window, int width, int height);

    void window_close_callback(GLFWwindow* window);
}

#endif