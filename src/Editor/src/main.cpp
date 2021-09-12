#include <iostream>
#include <memory>
#include <Application.hpp>

using namespace Retr0Engine;

class MyApp : public Application
{
private:
	int count;
public:
	MyApp(): count(0)
	{	}

	~MyApp()
	{	}

	void on_update() override 
	{
		//std::cout << "Update: " << count++ << std::endl;
	}
};

int main()
{
	auto app = std::make_unique<MyApp>();

	return app->start("Retr0Engine", 500, 600);
}