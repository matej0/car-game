#pragma once
#include "SDK.h"
#include "Controls.h"

//engine rpm / gearbox ratio / final gear ratio / revolutions per kilometer * 60 = kmh
//engine rpm = 8000
//gear ratios for a 4.10 gear ratio car (source some guy on the internet):
//1st 3.815 
//2nd 2.260 
//3rd 1.640 
//4th 1.177 
//5th 1.000 
//6th 0.832
//RPM = max throttle * current throttle
class CEngine
{
public:
	void DoStuff();

	int GetCurrentRPM()
	{
		return m_iCurrentRPM;
	};
	void SetCurrentRPM(int value)
	{
		m_iCurrentRPM = value;
	};

	//i know this is actually a part of the transmission but sue me.
	int GetCurrentGear()
	{
		return m_iGear;
	};
	void SetCurrentGear(int value)
	{
		m_iGear = value;
	};

	float GetCurrentGearRatio()
	{
		return m_flCurrentGearRatio;
	};
	void SetCurrentGearRatio(float value)
	{
		m_flCurrentGearRatio = value;
	};

	float GetCurrentTorque()
	{
		return m_flTorque;
	};
	void SetCurrentTorque(float value)
	{
		m_flTorque = value;
	};

private:
	std::vector<float> m_rgflRatios = { 0.0f, 3.8f, 2.2f, 1.6f, 1.1f, 0.9f, 0.7f };
	int m_iGear = 0;
	float m_flCurrentGearRatio = 0.0f;
	int m_iCurrentRPM = 0;
	const int m_iMaxRPM = 8000;
	float m_flTorque = 0.0f;

};

class CCar : public sf::RectangleShape
{

public:
	CCar()
	{
		this->setSize({ 30.f, 60.f });
		this->setPosition({ 400.f, 400.f });
		this->setFillColor(sf::Color::White);
		this->setOrigin({ this->getGlobalBounds().width / 2.f, (this->getGlobalBounds().height / 2.f) - 10.f });
	};

	void Think();
	float GetAngleOfRotation();
	float GetPointOfRotation();
	void MoveCar();

	CEngine* GetEngine()
	{
		return &Engine;
	};

	void DrawSelf();
	

private:
	sf::Transformable transformable;
	CEngine Engine;
	CControls Controls;
	sf::Vector2f m_vecVelocity;
	float m_flSpeed;
	float m_flAcceleration;
};