#include "stdafx.h"
#include "WinApp.h"
#include "resource.h"

WinApp::WinApp()
{
}


WinApp::~WinApp()
{
}

bool WinApp::Initalize(HINSTANCE hInstance, int nCmdShow)
{
	//UNREFERENCED_PARAMETER(hPrevInstance);
	//UNREFERENCED_PARAMETER(lpCmdLine);

	LoadStringW(hInstance, IDS_APP_TITLE, m_szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_TALESWEAVER, m_szWindowClassName, MAX_LOADSTRING);
	RegisterWindowClass(hInstance);

	m_hInstance = hInstance;

	m_hWnd = CreateWindowW(m_szWindowClassName, m_szTitle, WS_OVERLAPPEDWINDOW,
								CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!m_hWnd)
	{
		return FALSE;
	}

	ShowWindow(m_hWnd, nCmdShow);
	//UpdateWindow(m_hWnd);

	return true;
}

ATOM WinApp::RegisterWindowClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TALESWEAVER));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_TALESWEAVER);
	wcex.lpszClassName = m_szWindowClassName;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

bool WinApp::GameInit()
{
	return false;
}

void WinApp::Update(const float fElapsedTime)
{
}

void WinApp::Render()
{
}

int WinApp::GameLoop(WinApp &app)
{
	MSG msg{};

	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			GetMessage(&msg, NULL, 0, 0);
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// GameLoop
			app.Update(0);
			app.Render();
		}
	}
	return (int)msg.wParam;
}

LRESULT WinApp::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	//case WM_COMMAND:
	//{
	//	//int wmId = LOWORD(wParam);
	//	//// 메뉴 선택을 구문 분석합니다.
	//	//switch (wmId)
	//	//{
	//	//case IDM_ABOUT:
	//	//	DialogBox(m_hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
	//	//	break;
	//	//case IDM_EXIT:
	//	//	DestroyWindow(hWnd);
	//	//	break;
	//	//default:
	//	//	return DefWindowProc(hWnd, message, wParam, lParam);
	//	//}
	//}
	//break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다.
//		Rectangle(hdc, 10, 10, 60, 60);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
