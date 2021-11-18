#include <iostream>
#include <Application.hpp>
#include <Utils.hpp>

using namespace Retr0Engine;

class ExampleApp : Application
{
public:
	ExampleApp()
	{	}

	~ExampleApp()
	{	}

	int start(const char* title, unsigned int w_weidth, unsigned int w_heigth) override
	{
		return Application::start(title, w_weidth, w_heigth);
	}

	void on_update() override
	{
		
	}
};

int main()
{
	auto app = std::make_unique<ExampleApp>();

	app->start("Retr0Engine", 1100, 900);
}