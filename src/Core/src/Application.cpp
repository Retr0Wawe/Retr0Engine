#include "Application.hpp"
#include "Window.hpp"
#include "Log.hpp"

namespace Retr0Engine
{
    Application::Application()
    {
        LOG_INFO("Application has been started!");
    }

    Application::~Application()
    {
        LOG_INFO("Application has been closed!");
    }

    int Application::start(const char* title, uint32_t w_weidth, uint32_t w_heigth)
    {
        pWindow = std::make_unique<Window>(title, w_weidth, w_heigth);

        if (!result_code) {
            while (!a_Close_window) 
            {
                pWindow->on_update();
                this->on_update();
            }
        }
        return -1;
    }

    void Application::on_update(){  }
}
