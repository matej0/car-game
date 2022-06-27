#include "Controls.h"


void CControls::UpdateData()
{
	g_WheelData.m_flWheelPosition = map(g_Globals.Wheel.getAxisPosition(0, static_cast<sf::Joystick::Axis>(AXIS_WHEEL)), -100.f, 100.f, -900.f, 900.f) / 2.f;
	g_WheelData.m_flThrottle	  = map(-g_Globals.Wheel.getAxisPosition(0, static_cast<sf::Joystick::Axis>(AXIS_THROTTLE)), -100.f, 100.f, 0.f, 100.f);
	g_WheelData.m_flBrake         = map(-g_Globals.Wheel.getAxisPosition(0, static_cast<sf::Joystick::Axis>(AXIS_BRAKE)), -100.f, 100.f, 0.f, 100.f);
	g_WheelData.m_flClutch        = map(-g_Globals.Wheel.getAxisPosition(0, static_cast<sf::Joystick::Axis>(AXIS_CLUTCH)), -100.f, 100.f, 0.f, 100.f);

	if (g_Globals.Wheel.isButtonPressed(0, GEAR_FIRST))
		g_WheelData.m_iCurrentGear = 1;
	else if (g_Globals.Wheel.isButtonPressed(0, GEAR_SECOND))
		g_WheelData.m_iCurrentGear = 2;
	else if (g_Globals.Wheel.isButtonPressed(0, GEAR_THIRD))
		g_WheelData.m_iCurrentGear = 3;
	else if (g_Globals.Wheel.isButtonPressed(0, GEAR_FOURTH))
		g_WheelData.m_iCurrentGear = 4;
	else if (g_Globals.Wheel.isButtonPressed(0, GEAR_FIFTH))
		g_WheelData.m_iCurrentGear = 5;
	else if (g_Globals.Wheel.isButtonPressed(0, GEAR_SIXTH))
		g_WheelData.m_iCurrentGear = 6;
	else
		g_WheelData.m_iCurrentGear = 0;
}