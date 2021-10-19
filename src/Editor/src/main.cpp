#include <iostream>
#include <memory>
#include <Application.hpp>
#include <Utils.hpp>

using namespace Retr0Engine;

class MyApp : Application
{
private:
	int count;
public:
	MyApp(): count(0)
	{	}

	~MyApp()
	{	}

	int start(const char* title, unsigned int w_weidth, unsigned int w_heigth) override
	{
		Application::start(title, w_weidth, w_heigth);

		return -1;
	}

	void on_update() override 
	{
		//std::cout << "LOl" << std::endl;
	}
};

int main()
{
	//auto app = std::make_unique<MyApp>();

	//return app->start("Retr0Engine", 1000, 900);

	Retr0Str Lower = nullptr;
	Retr0Str a = Lower;
	Retr0Str b;
	std::cout << a.data() << std::endl;
}