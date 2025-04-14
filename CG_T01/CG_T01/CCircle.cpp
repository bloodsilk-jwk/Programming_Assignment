#include "CCircle.h"

CCircle::CCircle(float x, float y, float r)
	:CShape(x, y), m_r(r)
{
}

void CCircle::Draw(HDC hdc) const
{
	Ellipse(hdc, (GetX() - m_r), (GetY() - m_r), (GetX() + m_r), (GetY() + m_r));
}