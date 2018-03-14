#pragma once

#include "Singleton.h"

class WinApp
{
public:
	WinApp();
	~WinApp();

	virtual bool GameInit();
	virtual void Update(const float fElapsedTime);
	virtual void Render();
	virtual int  GameLoop(WinApp &app);
	

	bool Initalize(HINSTANCE hInstance, int nCmdShow);
	ATOM RegisterWindowClass(HINSTANCE hInstance);

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

protected :
	HINSTANCE m_hInstance;
	HWND      m_hWnd;
	//RECT      m_rtWindow;

	WCHAR	  m_szTitle[MAX_LOADSTRING];
	WCHAR	  m_szWindowClassName[MAX_LOADSTRING];

public :
	HWND GetHwnd() { return m_hWnd; }
};

