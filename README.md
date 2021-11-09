# Retr0Engine
## Simple 3d engine
### download: git clone https://github.com/Retr0Wawe/Retr0Engine --recursive
# Minimal example:
```
#include <iostream>
#include <Application.hpp>
#include <Utils.hpp>

using namespace Retr0Engine;

class MyApp : Application
{
public:
	MyApp()
	{	}

	~MyApp()
	{	}

	int start(const char* title, unsigned int w_weidth, unsigned int w_heigth) override
	{
		return Application::start(title, w_weidth, w_heigth);
	}

	void on_update() override
	{
		//std::cout << "LOl" << std::endl;
	}
};

int main()
{
	auto app = std::make_unique<MyApp>();

	return app->start("Retr0Engine", 1000, 900);
}
```cpp
