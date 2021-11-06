#include "Callback.hpp"

#include "Application.hpp"
#include "Log.hpp"

namespace Retr0Engine
{
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
           a_Close_window = true;
        }
    }

    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
    {
        
    }

    void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
    {
        //LOG_INFO("[Cursor position: {0}*{1}]", xpos, ypos);
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