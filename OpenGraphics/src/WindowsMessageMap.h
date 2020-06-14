#pragma once
#include <unordered_map>
#include <Windows.h>

class WindowsMessageMap
{
public:
	WindowsMessageMap();
	std::string operator()( DWORD msg,LPARAM lp,WPARAM wp ) const;
private:
	std::unordered_map<DWORD,std::string> map;
};

static int HandleEvents() {
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		// TranslateMessage will post auxilliary WM_CHAR messages from key msgs
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// check if GetMessage call itself borked
	if (gResult == -1)
	{
		return -1;
	}

	// wParam here is the value passed to PostQuitMessage
	return msg.wParam;
}