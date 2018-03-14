#pragma once

#include "Pen.h"

class Renderer 
{
public:
	Renderer(HWND hWnd);
	~Renderer();

	HDC Begin();
	void End();
	void Clear(HDC hDC, HBRUSH hBrush);
private :
	HWND    m_hWnd;
	RECT    m_rtWindow;
	HDC     m_hDC, m_hMemDC;
	HBITMAP m_hBitmap, m_hOldBitmap;
	
};

