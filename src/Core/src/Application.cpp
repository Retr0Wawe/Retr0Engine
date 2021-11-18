#include "Application.hpp"
#include "Window.hpp"
#include "Log.hpp"

using namespace std::chrono;

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

    int Application::start(const char* title, unsigned int w_weidth, unsigned int w_heigth)
    {
        pWindow = std::make_unique<Window>(title, w_weidth, w_heigth);

        while (!a_Close_window && !result_code)
        {
            pWindow->on_update();
            this->on_update();      //if you have 144ghz monitor, you need rewrite this function args to (1s / 144.0)
            //std::this_thread::sleep_for(duration_cast<milliseconds>(1s / 60.0));
        }

        return -1;
    }

    void Application::on_update()
    {
        return;
    }
}