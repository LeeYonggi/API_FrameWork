#include "stdafx.h"
#include "cImageManager.h"

//map<string, Texture*> m_TextureData;

bool cImageManager::AddImage(string str, LPCWSTR loute)
{
	auto iter = m_TextureData.find(str);
	if (iter == m_TextureData.end())
	{
		v_Texture.push_back(new Texture);

		int size = v_Texture.size() - 1;

		v_Texture[size]->tex = (HBITMAP)LoadImage(NULL, loute,
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		if (v_Texture[size]->tex == nullptr)
			return false;

		GetObject(v_Texture[size]->tex, sizeof(BITMAP), &v_Texture[size]->info);

		m_TextureData.insert(make_pair(str, v_Texture[size]));
	}
	else
		v_Texture.push_back(iter->second);

	texture = v_Texture[v_Texture.size() - 1];

	return true;
}

void cImageManager::DrawImage(HDC hdc, HDC backdc, Texture * tex, Position pos, int r, int g, int b, RECT cutImage, bool isCut)
{
	SelectObject(backdc, tex->tex);

	RECT size;
	if (isCut)
		size = cutImage;
	else
		size = { 0, 0, tex->info.bmWidth, tex->info.bmHeight };

	pos = { pos.x - (size.right - size.left) * 0.5f,  pos.y - (size.bottom - size.top) * 0.5f };

	SelectObject(backdc, tex);

	TransparentBlt(hdc, pos.x, pos.y, tex->info.bmWidth, tex->info.bmHeight, backdc,
		size.left, size.top, size.right, size.bottom, RGB(r, b, g));
}

cImageManager::cImageManager()
{
	nowImage = 0;
}


cImageManager::~cImageManager()
{
}
