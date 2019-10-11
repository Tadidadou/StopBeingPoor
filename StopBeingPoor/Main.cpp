#include "Map.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), WINDOW_TITLE);
	
	Map map;
	int pos = WINDOW_SIZE_X / 2 - MAP_SIZE_X / 2;
	int movement = 0;
	map.SetPosition(pos);
	map.SetGroundTexture("test_texture.jpg");

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
					movement = 1;
				else if (event.key.code == sf::Keyboard::Right)
					movement = -1;
			}
			else if (event.type == sf::Event::KeyReleased)
				movement = 0;
		}

		// Move the map
		map.Scroll(movement);

		window.clear();
		window.draw(map);
		window.display();
	}

	return 0;
}