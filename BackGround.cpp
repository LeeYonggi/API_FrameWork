#include "stdafx.h"
#include "BackGround.h"


void BackGround::Init()
{
	AddImage("backGround", L"./Image/����̹���/aquarium4.bmp");
	position = {320, 240};
}

void BackGround::Update(float deltaTime)
{
}

void BackGround::Render(HDC hdc, HDC backdc)
{
	DrawImage(hdc, backdc, texture, position, 255, 0, 255);
}

void BackGround::Release()
{
}

BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}
