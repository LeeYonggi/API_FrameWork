// API_FrameWork.cpp: 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "API_FrameWork.h"

#include <windows.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("API_FrameWork");
MainProc main;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{
	srand(time(NULL));
	HWND hWnd;
	MSG msg;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	CreateWND(hInstance);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, SCREEN_X, SCREEN_Y,
		NULL, (HMENU)NULL, hInstance, NULL);

	main.Init();

	ShowWindow(hWnd, nCmdShow);

	const float frame = 1.0f / 60.0f;

	INT64 lastTime = 0.0f;
	INT64 nowTime = 0.0f;
	double timeElapsed = 0.0f;

	lastTime = timeGetTime();
	float deltatime = 0.0f;

	float fpstime = timeGetTime();
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				return (int)msg.wParam;
			}
		}
		if(main.GetGameActive())
		{
			nowTime = timeGetTime();
			deltatime = nowTime - lastTime * 0.001f;

			if (deltatime >= frame)
			{
				main.Update(deltatime);
				main.Render(hWnd);
			}
		}
		if (msg.message == WM_QUIT)
			break;
	}
	main.Release();
	return (int)msg.wParam;
}

