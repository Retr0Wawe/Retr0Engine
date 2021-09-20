#include "Callback.hpp"

namespace Retr0Engine
{
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
           a_Close_window = true;
        }

        if (key == GLFW_KEY_A && action == GLFW_PRESS) {
            glClearColor(1, 0, 1, 0);
        }

        if (key == GLFW_KEY_D && action == GLFW_PRESS) {
            glClearColor(1, 1, 0, 1);
        }
    }

    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
    {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            LOG_INFO("[Button left pressed]");
            glClearColor(1, 0, 0, 1);
        }

        if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
            LOG_INFO("[Button right pressed]");
            glClearColor(0, 0, 1, 0);
        }
    }

    void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
    {
        LOG_INFO("[Cursor position: {0}*{1}]", xpos, ypos);
    }

    void window_size_callback(GLFWwindow* window, int width, int height)
    {
        LOG_INFO("[Window resized: {0}*{1}]", width, height);
    }

    void window_close_callback(GLFWwindow* window)
    {
        LOG_INFO("[Window closed]");
        a_Close_window = true;
    }
}