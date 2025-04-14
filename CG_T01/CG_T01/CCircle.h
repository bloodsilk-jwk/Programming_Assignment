#pragma once
#include "CShape.h"

class CCircle :
    public CShape
{
public:
    CCircle(float x, float y, float r);
    void Draw(HDC hdc) const;

private:
    float m_r;
};