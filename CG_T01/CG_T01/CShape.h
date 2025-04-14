#pragma once
#include <Windows.h>

class CShape
{
public:
	CShape(float x, float y);
	virtual void Draw(HDC hdc) const;

	float GetX() const;
	float GetY() const;

private:
	float m_x;
	float m_y;
};