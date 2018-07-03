#pragma once


class MainProc
{
private:
	bool gameActive;
	HBITMAP g_BackBitMap;
	BackGround *backGround;
	Stanley *stanley;
public:
	void Init();
	void Update(float deltaTime);
	void Render(HWND hWnd);
	void Release();

	void SetGameActive(bool active) { gameActive = active; }
	bool GetGameActive() { return gameActive; }

	MainProc() { gameActive = true; }
	~MainProc() { }
};