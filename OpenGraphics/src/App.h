#pragma once
#include "Window.h"
#include "Timer.h"

class App
{
public:
	App();
	// master frame / message loop
	int Run();
private:
	void Update();
private:
	Window wnd;
	Timer timer;
};