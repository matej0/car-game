#include "SDK.h"
GLOBALS g_Globals;
WHEELDATA g_WheelData;

//credits: https://www.arduino.cc/reference/en/language/functions/math/map/
float map(float x, float in_min, float in_max, float out_min, float out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void DrawString(sf::Vector2f vecPosition, int iCharSize, sf::Uint32 iStyle, sf::Font TextFont, sf::Color clrTextColor, sf::String strText, ...)
{
	static sf::RenderWindow* pRenderWindow = reinterpret_cast<sf::RenderWindow*>(g_Globals.pRenderWindowPointer);
	sf::Text text(strText, TextFont, iCharSize);
	text.setPosition(vecPosition);
	text.setFillColor(clrTextColor);
	pRenderWindow->draw(text);
}
