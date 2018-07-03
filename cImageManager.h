#pragma once

struct Texture
{
	HBITMAP tex;
	BITMAP info;
};

struct Position;

static map<string, Texture*> m_TextureData;

class cImageManager
{
protected:
	vector<Texture*> v_Texture;
	Texture *texture;

private:
	vector<RECT> v_AnimeRect;
	bool animeActive;
	int nowImage;

public:
	bool AddImage(string str, LPCWSTR loute);
	void PushAnimeRect(RECT rect);
	void DrawImage(HDC hdc, HDC backdc, Texture *tex, Position pos, int r, int g, int b, bool cutImage);

public:
	bool GetAnimeActive() { return animeActive; }
	void SetAnimeActive(bool active) { animeActive = active; }

public:

	cImageManager();
	virtual ~cImageManager();
};

