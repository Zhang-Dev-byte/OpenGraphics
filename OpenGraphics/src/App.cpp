#include "App.h"

App::App()
	:
	wnd(800, 600, "OpenGraphics")
{}

int App::Run()
{
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		// TranslateMessage will post auxilliary WM_CHAR messages from key msgs
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		Update();
	}

	// check if GetMessage call itself borked
	if (gResult == -1)
	{
		throw WND_LAST_EXCEPT();
	}

	// wParam here is the value passed to PostQuitMessage
	return msg.wParam;
}

void App::Update()
{
	wnd.Gfx().ClearBuffer(0.0f, 0.0f, 0.0f);
	wnd.Gfx().EndFrame();
}