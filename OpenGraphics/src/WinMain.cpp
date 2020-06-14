#define _MCBS
#include "Window.h"
#include "WindowsMessageMap.h"


int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow )
{
	try
	{
		Window wnd( 800,800,"Lol" );
		HDC hdc = GetDC(wnd.hWnd);

		for (int i = 0; i < 800; i++) {
			for (int j = 0; j < 800; j++) {
				SetPixel(hdc, i, j, RGB(0, 0, 0));
			}
		}

		return HandleEvents();
	}
	catch( const WException& e )
	{
		MessageBox( nullptr,e.what(),e.GetType(),MB_OK | MB_ICONEXCLAMATION );
	}
	catch( const std::exception& e )
	{
		MessageBox( nullptr,e.what(),"Standard Exception",MB_OK | MB_ICONEXCLAMATION );
	}
	catch( ... )
	{
		MessageBox( nullptr,"No details available","Unknown Exception",MB_OK | MB_ICONEXCLAMATION );
	}
	return -1;
}