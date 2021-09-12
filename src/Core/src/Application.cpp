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
        LOG_INFO("Closing application.");
    }

    int Application::start(const char* title, unsigned int w_weidth, unsigned int w_heigth)
    {
        pWindow = std::make_unique<Window>(title, w_weidth, w_heigth);

        while (pWindow)
        {
            pWindow->on_update();
            on_update();
        }

        return -1;
    }

    void Application::on_update()
    {
        LOG_INFO("Base func on_update");
    }
}