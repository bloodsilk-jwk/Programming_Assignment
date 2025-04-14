#include "CShape.h"

CShape::CShape(float x, float y)
	: m_x(x), m_y(y) 
{
}

void CShape::Draw(HDC hdc) const 
{

}

float CShape::GetX() const { return m_x; }
float CShape::GetY() const { return m_y; }
