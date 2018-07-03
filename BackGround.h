#pragma once
class BackGround :
	public Object
{
private:

public:
	void Init();
	void Update(float deltaTime);
	void Render(HDC hdc, HDC backdc);
	void Release();
	
	BackGround();
	virtual ~BackGround();
};

