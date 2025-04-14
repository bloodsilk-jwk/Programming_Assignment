// Filename : colorclass.cpp
#include "colorclass.h"

ColorClass::ColorClass()
{
	m_red = 0.0f;
	m_green = 0.0f;
	m_blue = 0.0f;
	m_alpha = 1.0f;

	m_brightness = 1.0f;
}

ColorClass::~ColorClass()
{
}

void ColorClass::setColor(float red, float green, float blue, float alpha)
{
	m_red = red;
	m_green = green;
	m_blue = blue;
	m_alpha = alpha;
}

float ColorClass::getRed()
{
	return m_red;
}
float ColorClass::getGreen()
{
	return m_green;
}
float ColorClass::getBlue()
{
	return m_blue;
}
float ColorClass::getAlpha()
{
	return m_alpha;
}

float ColorClass::getBrightness()
{
	return m_brightness;
}

void ColorClass::setBrightness(float value)
{
	m_brightness = value;
}