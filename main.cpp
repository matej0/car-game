#include "SDK.h"
#include "Car.h"





void ShowStuff()
{	
	float x = 10.f;
	float y = 20.f;

	DrawString({ x, y }, 12, sf::Text::Regular, g_Globals.Font, sf::Color::White, "throttle: " + std::to_string(g_WheelData.m_flThrottle));
	y += 14;
	DrawString({ x, y }, 12, sf::Text::Regular, g_Globals.Font, sf::Color::White, "brake: " + std::to_string(g_WheelData.m_flBrake));
	y += 14;
	DrawString({ x, y }, 12, sf::Text::Regular, g_Globals.Font, sf::Color::White, "clutch: " + std::to_string(g_WheelData.m_flClutch));
	y += 14;
	DrawString({ x, y }, 12, sf::Text::Regular, g_Globals.Font, sf::Color::White, "wheel: " + std::to_string(g_WheelData.m_flWheelPosition) + "°");
	y += 14;
	DrawString({ x, y }, 12, sf::Text::Regular, g_Globals.Font, sf::Color::White, "gear: " + std::to_string(g_WheelData.m_iCurrentGear));
	y += 14;
}



//a crude mockery of a car.
int main()
{
	//FILE* fp;
	//AllocConsole();
	//freopen_s(&fp, "CONOUT$", "w", stdout);

	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
	window.setFramerateLimit(144);

	g_Globals.pRenderWindowPointer = &window; //i should be executed for this.
	g_Globals.Font.loadFromFile("C:\\Windows\\Fonts\\Verdana.ttf");

	LogiSteeringInitialize(TRUE);
	
	sf::Clock deltaClock;
	CCar myCar;
	
	while (window.isOpen())
	{
		g_Globals.deltatime = deltaClock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		if (LogiUpdate())
		{
			g_Globals.pLogiWheelStates = LogiGetState(0);
			myCar.Think();

			ShowStuff();
		}


		window.display();
	}

	//fclose(fp);
	LogiSteeringShutdown();
	return 0;
}