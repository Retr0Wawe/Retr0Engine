# Retr0Engine
## Simple 3d engine
### download: git clone https://github.com/Retr0Wawe/Retr0Engine --recursive
# Minimal example:
```cpp
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
		return;
	}
};

int main()
{
	auto app = std::make_unique<ExampleApp>();

	app->start("Retr0Engine", 1100, 900);
}
```
![engine](https://user-images.githubusercontent.com/74567717/140999870-7cbde40e-575e-4606-9bc5-45925bc77171.png)

