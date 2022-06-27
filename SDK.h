#pragma once
#include <iostream>
#include <SFML/Graphics.hpp> //needs to be first otherwise shit starts to down
#include <Windows.h>
#include <Synchapi.h>
#include <windowsnumerics.h>
#define DIRECTINPUT_VERSION  0x0800
#include <dinput.h>
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")



#include <math.h>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <deque>
#include <random>
#include <sstream>
#include <string>
#include <string_view>

#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#pragma comment(lib, "LogitechSteeringWheelLib.lib")
#include "LogitechSteeringWheelLib.h"


#define PI 3.14159265358979323846f
#define RAD2DEG( x ) ( ( float )( x ) * ( float )( 180.0f / ( float )( PI ) ) )
#define DEG2RAD( x ) ( ( float )( x ) * ( float )( ( float )( PI ) / 180.0f ) )

struct GLOBALS
{
	void* pRenderWindowPointer;
	float deltatime;
	sf::Font Font;
	sf::Joystick Wheel;
	DIJOYSTATE2* pLogiWheelStates; //official data from the wheel, not used because "bogus" numbers.
};
extern GLOBALS g_Globals;


//credits: https://www.arduino.cc/reference/en/language/functions/math/map/
float map(float x, float in_min, float in_max, float out_min, float out_max);
void DrawString(sf::Vector2f vecPosition, int iCharSize, sf::Uint32 iStyle, sf::Font TextFont, sf::Color clrTextColor, sf::String strText, ...);

enum
{
	AXIS_WHEEL = 0,
	AXIS_THROTTLE = 1,
	AXIS_BRAKE = 3,
	AXIS_CLUTCH = 4,
	GEAR_FIRST = 12,
	GEAR_SECOND = 13,
	GEAR_THIRD = 14,
	GEAR_FOURTH = 15,
	GEAR_FIFTH = 16,
	GEAR_SIXTH = 17,
};

struct WHEELDATA 
{
	float m_flWheelPosition; // wheel position in degrees.
	float m_flThrottle; // throttle amount, 100 is fully pressed and -100 not pressed.
	float m_flBrake; // brake amount, 100 is fully pressed and -100 not pressed.
	float m_flClutch; // clutch amount, 100 is fully pressed and -100 not pressed.
	int   m_iCurrentGear; // 0 is neutral, rest is normal.
};
extern WHEELDATA g_WheelData;
