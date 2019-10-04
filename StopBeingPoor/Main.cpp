#include "Map.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), WINDOW_TITLE);
	
	Map map;
	map.SetGroundTexture("test_texture.jpg");
	map.SetPosition(MAP_SIZE_X / 2 + WINDOW_SIZE_X / 2);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) 
			{
				if (event.key.code == sf::Keyboard::Left)
					map.Scroll(map.GetPosition() + 10);
				else if (event.key.code == sf::Keyboard::Right)
					map.Scroll(map.GetPosition() - 10);
			}
		}

		window.clear();
		sf::Sprite groundSprite = map.GetGroundSprite();
		window.draw(groundSprite);
		window.display();
	}

	return 0;
}