#pragma once
#include "CShape.h"

class CRectangle :
    public CShape
{
public:
    CRectangle(float x, float y, float w, float h);
    void Draw(HDC hdc) const;

private:
    float m_w;
    float m_h;
};