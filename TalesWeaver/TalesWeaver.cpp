// TalesWeaver.cpp: 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "TalesWeaver.h"
#include "WinApp.h"
#include "TalesWeaverApp.h"

TalesWeaverApp g_talesApp;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	if (!g_talesApp.Initalize(hInstance, nCmdShow))
		return -1;

	if (!g_talesApp.GameInit())
		return -1;
		
    return g_talesApp.GameLoop(g_talesApp);
}

