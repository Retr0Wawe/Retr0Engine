#include <iostream>
#include <Application.hpp>
#include <Utils.hpp>

using namespace Retr0Engine;

class ExampleApp : public Application
{
public:
	ExampleApp()
	{	}

	~ExampleApp()
	{	}
};

int main()
{
	auto app = std::make_unique<ExampleApp>();

	app->start("Retr0Engine", 1000, 900);
}