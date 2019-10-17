#include "Map.h"
#include "Character.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), WINDOW_TITLE);
	
	Map map;
	int pos = WINDOW_SIZE_X / 2 - MAP_SIZE_X / 2;
	float movement = 0;
	map.SetPosition(pos);
	map.SetGroundTexture("Foreground/Tileset.png");
	map.SetBackgroundTexture("Background/BGFront.png");

	Character chara;
	chara.SetPosition(sf::Vector2f(400, WINDOW_SIZE_Y - HEIGHT_OF_GROUND - 28));
	chara.SetTexture("Characters/test-character.png");

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
					movement = -.5;
				else if (event.key.code == sf::Keyboard::Right)
					movement = .5;
			}
			else if (event.type == sf::Event::KeyReleased)
				movement = 0;
		}

		// Move the map
		map.Scroll(movement);
		chara.Move(movement);

		window.clear();
		window.draw(map);
		window.draw(chara);
		window.display();
	}

	return 0;
}