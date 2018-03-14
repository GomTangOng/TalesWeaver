#include "stdafx.h"
#include "TalesWeaverApp.h"
#include "Renderer.h"

TalesWeaverApp::TalesWeaverApp()
{
}


TalesWeaverApp::~TalesWeaverApp()
{
}

bool TalesWeaverApp::GameInit()
{
	m_pRenderer = make_shared<Renderer>(m_hWnd);
	return true;
}

void TalesWeaverApp::Update(const float fElapsedTime)
{

}

void TalesWeaverApp::Render()
{
	//// BeginPaint/EndPaint 쓸 수 없음...
	//HWND hWnd = GetHwnd();
	HPEN hNewPen, hOldPen;
	////HDC hdc = BeginPaint(hWnd, &ps);
	//HDC hdc = GetDC(hWnd);
	

	//ReleaseDC(hWnd, hdc);
	////EndPaint(hWnd, &ps);
	static int x = 10, dirX = 1;

	HDC hBackDC = m_pRenderer->Begin();

	
	EJ::Pen p;
	p.CreatePen(hBackDC);
	p.SetColor(RGB(255, 0, 0));
	
	Rectangle(hBackDC, x, 10, x + 60, 60);
	//p.SetColor(RGB(255,0,0));
	//p.SetWidth(10);
	

	//hNewPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	//hOldPen = (HPEN)SelectObject(hBackDC, hNewPen);

	//Rectangle(hBackDC, x, 10, x + 60, 60);

	//DeleteObject(SelectObject(hBackDC, hOldPen));
	//DeleteObject(hOldPen);
	
	p.~Pen();	// 이 부분 어떻게 해결할지 생각해야함.
	m_pRenderer->End();
}
