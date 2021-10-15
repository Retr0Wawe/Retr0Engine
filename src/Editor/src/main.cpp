#include <iostream>
#include <memory>
#include <Application.hpp>
#include <utils/Retr0Str.hpp> 

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

	Retr0Str str = "Lowe";
	Retr0Str lower = "Lowerd";
	Retr0Str a;

	if (str > lower) {
		std::cout << "FUCCl";
	}

	std::cout << a.data() << std::endl;
}