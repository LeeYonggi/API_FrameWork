#include "stdafx.h"
#include "MainProc.h"


void MainProc::Init()
{
	backGround = new BackGround;
	backGround->Init();
	stanley = new Stanley;
	stanley->Init();
}

void MainProc::Update(float deltaTime)
{
	backGround->Update(deltaTime);
	stanley->Update(deltaTime);
}

void MainProc::Render(HWND hWnd)
{
	HDC hdc, _MemDC, _BackDC;
	HBITMAP hPreBit;
	PAINTSTRUCT ps;

	hdc = BeginPaint(hWnd, &ps);

	_MemDC = CreateCompatibleDC(hdc);

	g_BackBitMap = CreateCompatibleBitmap(hdc, 800, 600);

	hPreBit = (HBITMAP)SelectObject(_MemDC, g_BackBitMap);

	_BackDC = CreateCompatibleDC(hdc);

	ObjectRender(_MemDC, _BackDC);

	DeleteObject(_BackDC);

	BitBlt(hdc, 0, 0, 800, 600, _MemDC, 0, 0, SRCCOPY);

	SelectObject(_MemDC, hPreBit);
	DeleteObject(g_BackBitMap);
	DeleteDC(_MemDC);

	EndPaint(hWnd, &ps);
	InvalidateRect(hWnd, NULL, FALSE);
}

void MainProc::ObjectRender(HDC memDc, HDC backDc)
{
	backGround->Render(memDc, backDc);
	stanley->Render(memDc, backDc);
}

void MainProc::Release()
{
	for (auto iter : m_TextureData)
	{
		if (iter.second)
			delete iter.second;
	}
	m_TextureData.clear();
	if (backGround)
		delete backGround;
	if (stanley)
		delete stanley;
}
