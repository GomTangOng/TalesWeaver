#include "stdafx.h"
#include "Renderer.h"


Renderer::Renderer(HWND hWnd)
{
	m_hWnd = hWnd;
}


Renderer::~Renderer()
{
}

HDC Renderer::Begin()
{
	RECT crt;
	GetClientRect(m_hWnd, &m_rtWindow);

	m_hDC = GetDC(m_hWnd);
	if (m_hBitmap == NULL) 
		m_hBitmap = CreateCompatibleBitmap(m_hDC, m_rtWindow.right, m_rtWindow.bottom);
	
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);
	Clear(m_hMemDC, GetSysColorBrush(COLOR_WINDOW));
	return m_hMemDC;
}

void Renderer::End()
{
	BitBlt(m_hDC, 0, 0, m_rtWindow.right, m_rtWindow.bottom, m_hMemDC, 0, 0, SRCCOPY);
	m_hBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hOldBitmap);
	DeleteDC(m_hMemDC);
	ReleaseDC(m_hWnd, m_hDC);
}

void Renderer::Clear(HDC hDC, HBRUSH hBrush)
{
	FillRect(hDC, &m_rtWindow, hBrush);
}
