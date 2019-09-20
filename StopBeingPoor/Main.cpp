#include "Constants.h"
#include "Map.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), WINDOW_TITLE);
	
	Map map;
	sf::Sprite mapSprite;
	mapSprite = map.DrawMap(MAP_TEXTURE_FILE_NAME);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(mapSprite);
		window.display();
	}

	return 0;
}