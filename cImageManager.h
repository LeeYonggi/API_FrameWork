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
	bool animeActive;
	int nowImage;

public:
	bool AddImage(string str, LPCWSTR loute);
	void DrawImage(HDC hdc, HDC backdc, Texture *tex, Position pos, int r, int g, int b, RECT cutImage);
	void DrawImage(HDC hdc, HDC backdc, Texture *tex, Position pos, int r, int g, int b);

public:
	bool GetAnimeActive() { return animeActive; }
	void SetAnimeActive(bool active) { animeActive = active; }

public:

	cImageManager();
	virtual ~cImageManager();
};

