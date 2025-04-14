// Filename : colorclass.h
#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_


// class name : ColorClass
class ColorClass
{
public:
	ColorClass();
	~ColorClass();
	void setColor(float, float, float, float);
	float getRed();
	float getGreen();
	float getBlue();
	float getAlpha();

	float getBrightness();
	void setBrightness(float);
private:
	float m_red;
	float m_green;
	float m_blue;
	float m_alpha;

	float m_brightness;
};

#endif