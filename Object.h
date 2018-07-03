#pragma once

struct Position
{
	float x, y;
};

class Object :
	public cImageManager
{
protected:
	Position position;

public:
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(HDC hdc, HDC backdc) = 0;
	virtual void Release() = 0;

	Object();
	virtual ~Object();
};

