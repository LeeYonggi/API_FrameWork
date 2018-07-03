#include "stdafx.h"
#include "MainProc.h"


void MainProc::Init()
{
	backGround = new BackGround;
	backGround->Init();
}

void MainProc::Update(float deltaTime)
{
	backGround->Update(deltaTime);
}

void MainProc::Render(HWND hWnd)
{
	HDC hdc, MemDC, BackDC;
	HBITMAP hPreBit;
	PAINTSTRUCT ps;

	hdc = BeginPaint(hWnd, &ps);

	MemDC = CreateCompatibleDC(hdc);

	g_BackBitMap = CreateCompatibleBitmap(hdc, 800, 600);

	hPreBit = (HBITMAP)SelectObject(MemDC, g_BackBitMap);

	BackDC = CreateCompatibleDC(hdc);

	backGround->Render(MemDC, BackDC);

	DeleteObject(BackDC);

	BitBlt(hdc, 0, 0, 800, 600, MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, hPreBit);
	DeleteObject(g_BackBitMap);
	DeleteDC(MemDC);

	EndPaint(hWnd, &ps);
}

void MainProc::Release()
{
	for (auto iter : m_TextureData)
	{
		if (iter.second)
			delete iter.second;
	}
	m_TextureData.clear();
}
