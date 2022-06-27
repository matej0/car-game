#include "Car.h"

void CCar::Think()
{
	this->Controls.UpdateData();
	this->GetEngine()->DoStuff();
	this->MoveCar();
	this->DrawSelf();
}

//torque = horsepower * 5252 / rpm
//force = m * a -> a = force / mass where force is basically torque divided by wheel radius except we have no wheels.


void CEngine::DoStuff()
{
	if (g_WheelData.m_flClutch >= 70.f)
	{
		this->SetCurrentGear(g_WheelData.m_iCurrentGear);
		this->SetCurrentGearRatio(this->m_rgflRatios.at(this->GetCurrentGear()));
	}

	float flThrottle = g_WheelData.m_flThrottle;
	float flRPM = (flThrottle / 100.f) * this->m_iMaxRPM;
	this->SetCurrentRPM(int(flRPM));

	float flTorque = 0.0f;

	if (this->GetCurrentGear() != 0 && flRPM > 0.f && this->GetCurrentGearRatio() > 0.0000f)
	{
		flTorque = (flThrottle / 100.f) * this->GetCurrentGearRatio();
		this->SetCurrentTorque(flTorque);
	}

	DrawString({ 10.f, 150.f }, 12, sf::Text::Regular, g_Globals.Font, sf::Color::White, "rpm: " + std::to_string(flRPM));
	DrawString({ 10.f, 164.f }, 12, sf::Text::Regular, g_Globals.Font, sf::Color::White, "current gear: " + std::to_string(this->GetCurrentGear()));
	DrawString({ 10.f, 180.f }, 12, sf::Text::Regular, g_Globals.Font, sf::Color::White, "current gear ratio: " + std::to_string(this->GetCurrentGearRatio()));
	DrawString({ 10.f, 194.f }, 12, sf::Text::Regular, g_Globals.Font, sf::Color::White, "torque: " + std::to_string(flTorque));
}



float CCar::GetAngleOfRotation()
{
	float ang = 0.0f;
	float wheelang = map(g_WheelData.m_flWheelPosition, -450.f, 450.f, -65.f, 65.f);

	sf::Vector2f vecDelta = sf::Vector2f();
	//vecDelta = sf:

	return wheelang;
}

//Ackerman steering model.
float CCar::GetPointOfRotation()
{
	float radius = (this->getSize().y) / std::tanf(-(DEG2RAD(GetAngleOfRotation())));
	return -radius;
}

void CCar::MoveCar()
{
	float ang = this->GetAngleOfRotation();

	//sf::Vector2f center;
	//center.x = this->getPosition().x + GetPointOfRotation();
	//center.y = this->getPosition().y + 40.f;


	this->setRotation(ang);

	this->m_flAcceleration = (this->GetEngine()->GetCurrentTorque() / 15.f);
	std::roundf(m_flAcceleration);

	this->m_flSpeed += m_flAcceleration;

	if (m_flSpeed > 0.f)
	{
		const float m_flFriction = 0.1f;
		m_flSpeed -= m_flFriction;
	}
	
	if (m_flSpeed > 200.f)
		this->m_flSpeed = 200.f;

	DrawString({ 10.f, 210.f }, 12, sf::Text::Regular, g_Globals.Font, sf::Color::White, "speed: " + std::to_string(m_flSpeed));
	DrawString({ 10.f, 224.f }, 12, sf::Text::Regular, g_Globals.Font, sf::Color::White, "acc: " + std::to_string(m_flAcceleration));
	DrawString({ 10.f, 240.f }, 12, sf::Text::Regular, g_Globals.Font, sf::Color::White, "radius: " + std::to_string(GetPointOfRotation()));
	DrawString({ 10.f, 254.f }, 12, sf::Text::Regular, g_Globals.Font, sf::Color::White, "wheel ang: " + std::to_string(GetAngleOfRotation()));

	
	

	this->m_vecVelocity.x = std::cos(DEG2RAD(this->getRotation() - 90)) * m_flSpeed * g_Globals.deltatime;
	this->m_vecVelocity.y = std::sin(DEG2RAD(this->getRotation() - 90)) * m_flSpeed * g_Globals.deltatime;
	//sf::Transformable trans;
	

	

	sf::RectangleShape line(sf::Vector2f(2.f, GetPointOfRotation()));
	line.setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y + 40.f));
	line.setRotation(GetAngleOfRotation() - 90.f);
	static sf::RenderWindow* pRenderWindow = reinterpret_cast<sf::RenderWindow*>(g_Globals.pRenderWindowPointer);
	pRenderWindow->draw(line);


	this->move(m_vecVelocity);
}

void CCar::DrawSelf()
{

	static sf::RenderWindow* pRenderWindow = reinterpret_cast<sf::RenderWindow*>(g_Globals.pRenderWindowPointer);

	pRenderWindow->draw(*this);
	
}